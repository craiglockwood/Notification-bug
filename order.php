<?php
        $ch = curl_init("https://api.spark.io/v1/devices/photon1/order?access_token=ACCESS_TOKEN_HERE");
        curl_setopt($ch, CURLOPT_HEADER, 0);
        curl_setopt($ch, CURLOPT_POST, 1);
        curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
        $output = curl_exec($ch);       
        curl_close($ch);
        echo $output;
?>



