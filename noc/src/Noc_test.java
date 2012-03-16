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
		
		if(CPUID == 0){ // Core zero waits for all other cores to reply
			for(;;){
				if(Native.rd(MAXCPU+1) == 511){ // All cores have sent their reply
					Native.wr(43,255);
				}
			}
		}
		
		for(;;){
			if(Native.rd(MAXCPU) == 0){
				// Tx status register is all zero.
				break;
			}
		}
		for(int i = 1; i != MAXCPU; i++){ // Do not send a message to core zero.
			// Send CPUID to core number i.
			Native.wr(CPUID,i);
		}
		
		for(;;){
			if(Native.rd(MAXCPU+1) == 511){
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

	
 

 