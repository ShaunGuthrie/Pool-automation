Welcome to yet another Pool-automation wiki!
I have no clue what im doing so any input is welcome.  I'm using a Lilygo T relay with a 4 x 20 LCD, 3 Dallas temp sensors and a few other components ill post as I go along.  Im basically making Dumb pool equipment less dumb.  My goal is to have every smart device run locally with Home assistant being the bridge.  If for any reason HA goes down the device will continue to operate independently. 
![514CT8gaWgL _AC_SL1000_](https://github.com/user-attachments/assets/6623c8d6-98ed-4d80-a219-f4608857c9cc)

The 4 relays control 3 speeds of the pump, and the heater contact.  The temp sensors are for Ambient air temp, pre heater water temp and post heater water temp.  The post heater temp will just be used to monitor that the heater works, and be a safety.

The display shows water and air temp, heater mode and status, heater set point, and pump speed.

The heater will be controlled via the external contact with the t relay acting as the thermostat so any heater should be able to be controlled.

Pump control is for any pump with dry contacts. The pump I am currently controlling is a generic 2 speed pump.  The low and high relay are tied to 25A SSRs that are wired to the low and high terminals separately.  Lockout to prevent both SS relays closing at once is via an interlock group and the common of each Lilygo relay is tied to the NC of the prior.

I plan to control an Aqua Rite SWCG as well but im just digging into that now.
 

