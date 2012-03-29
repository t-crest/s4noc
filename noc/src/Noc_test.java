import com.muvium.leros.Native;
import com.muvium.MuviumRunnable;

/*
 * Test of the NoC with block ram in the NI
 * 
 */

public class Noc_test extends MuviumRunnable {
    
    public void run(){
		int CPUID = Native.rd(253);
		int MAXCPU = Native.rd(252);
		int status = 0;
		int mask = -1;
		mask = mask -1;
		
		if(CPUID == 0){ // Core zero waits for all other cores to reply
		    //for(;;){
			//Native.wr(65,255);
			//for(int i = 0; i != 10; i++){
			//	status++;
			//}
			//status = Native.rd(17);
			//Native.wr(status,255);
			// }
		    //  Native.wr(CPUID,255);
		    for(;;){
				Native.wr(65,255);
				//if(Native.rd(254) == 1){
				//	status = Native.rd(17);
					//status = status + 1;
				//	Native.wr(status,255);
				//Native.wr(Native.rd(17),255);
				//	if(status == 65535){ // All cores have sent their reply
				//		Native.wr(43,255);
						//	for(;;){}
				//	}
				//}
		    }
		}
		
		// for(;;){
		// 	if(Native.rd(16) == 0){
		// 		// Tx status register is all zero.
		// 		break;
		// 	}
		// }
		//		for(int i = 1; i != MAXCPU; i++){ // Do not send a message to core zero.
			// Send CPUID to core number i.

		Native.wr(CPUID,1);
		Native.wr(CPUID,2);
		Native.wr(CPUID,3);
		Native.wr(CPUID,4);
		Native.wr(CPUID,5);
		Native.wr(CPUID,6);
		Native.wr(CPUID,7);
		Native.wr(CPUID,8);
		Native.wr(CPUID,9);
		Native.wr(CPUID,10);
		Native.wr(CPUID,11);
		Native.wr(CPUID,12);
		Native.wr(CPUID,13);
		Native.wr(CPUID,14);
		Native.wr(CPUID,15);
			//		}
		
		for(;;){
			if(Native.rd(17) == mask){
				// Rx status register is all one and all messages are received.
				break;
			}
		}
		
		Native.wr(CPUID,0); // Send a packet to core zero
		
		for(;;){
			status++;
		}
	}
}

	
 

 
