import java.net.DatagramSocket;
import java.io.*;
import java.net.*;
public class Client {

    private DatagramSocket socket = null;
    public Client(String address, int port){
        try{
            socket = new DatagramSocket();
            InetAddress host = InetAddress.getByName(address);
            String s = "Orasan Paul-Dumitru";
            byte[] b = s.getBytes();

            DatagramPacket  dp = new DatagramPacket(b , b.length , host , port);
            socket.send(dp);


        }catch(IOException e){
            System.out.println(e);
        }
    }

    public static void main(String[] args) {
        // write your code here
        Client main = new Client("193.231.20.3", 1276);
    }
}