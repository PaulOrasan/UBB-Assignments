import javax.xml.crypto.Data;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.charset.StandardCharsets;
import java.sql.SQLOutput;

public class Server extends Thread{

    private DatagramSocket socket;
    private byte[] buffer = new byte[256];

    public Server() {
        try {
            socket = new DatagramSocket(5000);

        } catch (IOException i) {
            System.out.println(i);
        }
    }

    public void run(){
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length);

        try{
            socket.receive(packet);
            InetAddress address = packet.getAddress();
            int port = packet.getPort();
            Thread writer = new Thread(new Runnable(){
                public void run(){
                    String s;
                    DataInputStream dis = new DataInputStream(System.in);
                    while(true) {
                        try {
                            byte[] buf;
                            s = dis.readLine();
                            buf = s.getBytes();
                            socket.send(new DatagramPacket(buf, buf.length, address, port));
                            if(s.equals("exit"))
                                System.exit(0);
                        } catch (IOException i) {
                            System.out.println(i);
                        }
                    }

                }
            });
            writer.start();
            while (true) {
                packet = new DatagramPacket(buffer, buffer.length);
                socket.receive(packet);
                String received = new String(packet.getData(), 0, packet.getLength());
                System.out.println(address + ": "+received);
                if(received.equals("exit")){
                    System.exit(0);
                }
            }


        }catch(IOException i){
            System.out.println(i);
        }

    }

}