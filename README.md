# Notification-bug

###A standlaone device to alert Shopify store owners of sales, cart updates or traffic spikes.

Parts required:   
Photon wifi Dev kit   
Neopixels Jewel - 7 pixel RGB   
Wire   
Solder   
USB lead   
PLA for 3D printer   

Full details on the Shopify Partners blog at : xxxxxxxxxxxxx.com

###Short version: 

Add access token for your Particle Photon to the end of the URL on line 2 of cart.php, order.php & spike.php.

Upload cart.php, order.php & spike.php to any PHP server taking note pf the URL.

Copy the code from Photon_code.ino into the Particle IDE (https://www.particle.io/build) for your registered device.

In Shopify go to Settings> Notifications> Create a webhook  - Create an event and enter the URL of the PHP file you have uploaded.

Sit back & enjoy.
