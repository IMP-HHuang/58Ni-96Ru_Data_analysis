/**
 * Decode.java
 * Decode the data
 * H.Huang 2022.10.20
 */

import fi.jyu.phys.grain.sort.*;  //类似于#include
import fi.jyu.phys.grain.sort.detector.*;
import fi.jyu.phys.grain.sort.gates.*;
import fi.jyu.phys.grain.resources.GrainConstants;
import hep.aida.*;
import java.util.*;
import java.text.NumberFormat;
import java.nio.*;
import java.nio.channels.*;
import java.io.*;

public class Decode extends GrainJuroGamSorter //继承GrainJuroGamSorter类，命名为calib_cs
{
	File out_file = null;
	OutputStreamWriter out_object = null;
	double i = 0;
	public void initialise()
	{
		try{
			//output file
			out_file = new File("./txt/datatmptmp.txt");
			out_object = new OutputStreamWriter(new FileOutputStream(out_file), "utf-8");
         }   
         catch (Exception ex)
         {
             System.out.println("File error");
         }  
	}

	public void process() 
	{
		//DSSD 死层修正
		event.strip.e -= 50;
		event.juro.dopplerCorrect(0.034);
//		System.out.println(event.strip.e);
		//MWPC
		try{
		//	out_object.write(event.stamp+"\t"+event.stamp/GrainConstants.TDR_M+"\t"+event.sigastac.t+" \n");
			out_object.write(event.stamp+"\t"+event.sigastac.t+" \n");
	//		out_object.write("MWPC: \n");
			//注意调整读入程序
			if(event.gas.de > 0)
			{
				out_object.write(event.gas.de+"\t"+event.gas.time+"\t"+event.gas.x1+"\t"+event.gas.x2+"\t"+event.gas.y1+"\t"+event.gas.y2+"\n");
				out_object.write(event.gas.fail+"\t"+event.gas.piledup+"\t"+event.gas.valid+"\t"+event.gas.vetoed+"\n");
			}
			else out_object.write(event.gas.de+"\n");
		}catch (Exception ex){}
		//DSSD
		try{
	//		out_object.write("DSSD:\n");
		//	out_object.write(event.strip.e+"\t"+event.strip.x+"\t"+event.strip.y+"\n");
		}
		catch (Exception ex)
		{}
		try{
			out_object.write("\n"+event.strip.xcount+"\n");
		}catch (Exception ex){}

		for(GrainDetectorStrip DSSDx : event.strip.xstrips)
		{	
			try{
				out_object.write(DSSDx.e+"\t"+DSSDx.oe+"\t"+DSSDx.coord+"\t"+DSSDx.time+"\n");
//				out_object.write(DSSDx.oe+"\t"+DSSDx.coord+"\t"+DSSDx.time+"\n");
				out_object.write(DSSDx.fail+"\t"+DSSDx.piledup+"\t"+DSSDx.valid+"\t"+DSSDx.vetoed+"\n");
			}catch (Exception ex){}
		}

		try{
			out_object.write("\n"+event.strip.ycount+"\n");
		}catch (Exception ex){}
		for(GrainDetectorStrip DSSDy : event.strip.ystrips)
		{
			try{
				out_object.write(DSSDy.e+"\t"+DSSDy.oe+"\t"+DSSDy.coord+"\t"+DSSDy.time+"\n");
	//			out_object.write(DSSDy.oe+"\t"+DSSDy.coord+"\t"+DSSDy.time+"\n");
				out_object.write(DSSDy.fail+"\t"+DSSDy.piledup+"\t"+DSSDy.valid+"\t"+DSSDy.vetoed+"\n");
			}catch (Exception ex){}
		}
		//Pin Diode
		i = 0;
		for( GrainDetectorPin pin: event.pinarray.pins)  i++;
		try{
		//	out_object.write("Pin_Diode:\n"+i+"\n");
			out_object.write(i+"\n");
		}catch (Exception ex){}
		
		for( GrainDetectorPin pin: event.pinarray.pins)
		{
			try{
				out_object.write(pin.e+"\t"+pin.oe+"\t"+pin.number+"\t"+pin.time+"\n");
				out_object.write(pin.fail+"\t"+pin.piledup+"\t"+pin.valid+"\t"+pin.vetoed+"\n");
			}catch (Exception ex){}
		}		
		//Planar GE
		try{
//			out_object.write("Planar_GE:\n");
//			out_object.write(event.planar.e+"\t"+event.planar.x+"\t"+event.planar.y+"\n");	
		}catch (Exception ex){}
		try{
			out_object.write("\n"+event.planar.xcount+"\n");
		}catch(Exception ex){}
		for( GrainDetectorStrip planarx : event.planar.xstrips)
		{
			try{
				out_object.write(planarx.e+"\t"+planarx.oe+"\t"+planarx.coord+"\t"+planarx.time+"\n");
				out_object.write(planarx.fail+"\t"+planarx.piledup+"\t"+planarx.valid+"\t"+planarx.vetoed+"\n");
			}catch (Exception ex){}
		}
		try{
			out_object.write("\n"+event.planar.ycount+"\n");
		}catch(Exception ex){}
		for( GrainDetectorStrip planary : event.planar.ystrips)
		{
			try{
				out_object.write(planary.e+"\t"+planary.oe+"\t"+planary.coord+"\t"+planary.time+"\n");
				out_object.write(planary.fail+"\t"+planary.piledup+"\t"+planary.valid+"\t"+planary.vetoed+"\n");
			}catch (Exception ex){}
		}
		//Clover
		i = 0;
		for( GrainDetectorGermanium clover : event.fparray.ges)  i++;
		try{
	//		out_object.write("Clover:\n"+i+"\n");
			out_object.write(i+"\n");
		}catch (Exception ex){}

		for( GrainDetectorGermanium clover : event.fparray.ges)
		{
			try{
			//	out_object.write(clover.number+"\t"+clover.e+"\t"+clover.oe+"\t"+clover.time+"\t"+clover.phi+"\t"+clover.theta+"\t"+clover.ring+"\n");
				out_object.write(clover.number+"\t"+clover.e+"\t"+clover.oe+"\t"+clover.time+"\n");
				out_object.write(clover.fail+"\t"+clover.piledup+"\t"+clover.valid+"\t"+clover.vetoed+"\n");
			}catch (Exception ex){}
		}
		// Ge
		i = 0;
		for( GrainDetectorGermanium ge : event.juro.ges)  i++;
		try{
		//	out_object.write("Ge:\n"+i+"\n");
			out_object.write(i+"\n");
		}catch (Exception ex){}
		for( GrainDetectorGermanium ge : event.juro.ges)
		{
			try{
				out_object.write(ge.number+"\t"+ge.e+"\t"+ge.oe+"\t"+ge.time+"\t"+ge.phi+"\t"+ge.theta+"\t"+ge.ring+"\n");
				out_object.write(ge.fail+"\t"+ge.piledup+"\t"+ge.valid+"\t"+ge.vetoed+"\n");
			}catch (Exception ex){}
		}

		try{
//			out_object.write("\n********************************************************************* \n");
		}catch(Exception ex){}
	}
		public void finalise() 
			{
				try{
				}catch (Exception ex)
				{}
			}
		public boolean PinVetoNeeded() 
			{

				for( GrainDetectorPin p: event.pinarray.pins)
					{
						double PinTime = (p.time-event.stamp);	    					
//						if((p.fail) || apin_gate.passes(PinTime))
								return true;			
					}
				return false;
			}

}

