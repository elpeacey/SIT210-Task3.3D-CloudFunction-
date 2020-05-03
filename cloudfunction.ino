int led = D7;

void setup() {

	pinMode(led,OUTPUT); 
	
	Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", handler);
}


// Now for the myHandler function, which is called when the cloud tells us that our buddy's event is published.
void handler(const char *event, const char *data)
{
    //Flash 3 times if data = "wave"
	if (strcmp(data,"wave") == 0) {
		for (int i = 0; i < 3; i++) {   
    		digitalWrite(led,HIGH);
    		delay(500);
    		digitalWrite(led,LOW);
    		delay(500);
	    }
	}
	
	//Flash 5 times if data = "pat"
	else if (strcmp(data, "pat") == 0) {
	    for (int i = 0; i < 5; i++) {
    	    digitalWrite(led,HIGH);
    		delay(500);
    		digitalWrite(led,LOW);
    		delay(500);
        }
	}
	
}