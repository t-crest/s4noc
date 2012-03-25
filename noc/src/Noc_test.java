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
			Native.wr(65,255);

			// }
		    //  Native.wr(CPUID,255);
		    for(;;){
			if(Native.rd(17) == 65535){ // All cores have sent their reply
			    Native.wr(43,255);
			    for(;;){}
			}
			
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

		Native.wr(16,1);
		Native.wr(16,2);
		Native.wr(16,3);
		Native.wr(16,4);
		Native.wr(16,5);
		Native.wr(16,6);
		Native.wr(16,7);
		Native.wr(16,8);
		Native.wr(16,9);
		Native.wr(16,10);
		Native.wr(16,11);
		Native.wr(16,12);
		Native.wr(16,13);
		Native.wr(16,14);
		Native.wr(16,15);
			//		}
		
		for(;;){
			if(Native.rd(17) == mask){
				// Rx status register is all one and all messages are received.
				break;
			}
		}
		
		Native.wr(111,0); // Send a packet to core zero
		
		for(;;){
			status++;
		}
	}
}

	
 

 
