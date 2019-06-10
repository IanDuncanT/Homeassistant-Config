echo "-----------------------------------------------"
echo "Updating SSL Certificates"
echo "-----------------------------------------------"
echo "Stopping Webserver"
sudo service apache2 stop
echo "-----------------------------------------------"
echo "Renewing SSL Certificates"
sudo certbot renew
echo "-----------------------------------------------"
echo "Starting Webserver"
sudo service apache2 start
echo "-----------------------------------------------"
echo "Finished Updating SSL Certificates"
echo "-----------------------------------------------"
