import com.muvium.leros.Native;
import com.muvium.MuviumRunnable;

/*
 * Example program for Leros.
 * Just a simple blinking LED.
 * 
 */

public class Test extends MuviumRunnable {
    
    
    //	private static void delayMs( int milliseconds ){
    //		for (int i= milliseconds; i != 0; i--)
    //			 for (int j=2000; j != 0; j--);
    //	}
    
    public void run(){
	int status = 0;
	//	for (;;) {
	status = Native.rd(128);
	if(( status & 7) == 0){
	    Native.wr(15, 0);
	    //	    break;
	}
	//	}
	
	for(int j = 0; j != 2; j++) {
	    status = Native.rd(128);
	    if (( status & 112) == 16){ // Tile 1
		int token = Native.rd(15);
		Native.wr(token,127);
		for(;;){
		    status = Native.rd(128);
		    if((status & 112) == 16 ){
			token = Native.rd(15);
			Native.wr(token,127);
		    }
		}
	    }
	}
	// Tile 2
	int number = 43;
	for(;;){
	    status = Native.rd(128);
	    if (( status & 7) == 0){
		Native.wr(number,0);
		number++;
	    }
	}
	
    }
    
}

	
 

 