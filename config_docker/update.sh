echo "-----------------------------------------------"
echo "Updating Docker Containers"
echo "-----------------------------------------------"
cd /home/$USER/volume-docker 
echo "In User Folder"
echo "-----------------------------------------------"
echo "Stopping Docker Containers"
docker-compose down --remove-orphans
echo "-----------------------------------------------"
echo "Pulling Docker Images"
docker-compose pull
echo "-----------------------------------------------"
echo "Starting Docker Containers"
docker-compose up -d
echo "-----------------------------------------------"
echo "Pruning Docker Images"
docker image prune -af
echo "-----------------------------------------------"
echo "Finished Updating Docker Containers"
echo "-----------------------------------------------"
