import javax.xml.crypto.Data;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.charset.StandardCharsets;
import java.sql.SQLOutput;

public class Client extends Thread{

    private DatagramSocket socket;
    private byte[] buffer = new byte[256];
    private InetAddress address;
    public Client() {
        try {
            socket = new DatagramSocket();
            address = InetAddress.getByName("localhost");

        } catch (IOException i) {
            System.out.println(i);
        }
    }

    public void run(){
        String msg = "Eu";
        buffer = msg.getBytes();
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length, address, 5000);
        buffer = new byte[256];
        try{
            socket.send(packet);
            Thread writer = new Thread(new Runnable(){
                public void run(){
                    String s;
                    DataInputStream dis = new DataInputStream(System.in);
                    while(true) {
                        try {
                            byte[] buf;
                            s = dis.readLine();
                            buf = s.getBytes();
                            socket.send(new DatagramPacket(buf, buf.length, address, 5000));
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
                System.out.println(received);
                if(received.equals("exit"))
                    System.exit(0);
            }


        }catch(IOException i){
            System.out.println(i);
        }

    }

}