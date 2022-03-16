import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Telefon> telefoane = new ArrayList<>();
        telefoane.add(new Telefon("iPhone 13 Pro", 6300));
        telefoane.add(new Telefon("Galaxy S21 Plus", 4200));
        telefoane.add(new Telefon("Pixel 6", 4600));
        telefoane.add(new Telefon("Galaxy Note 20", 6200));
        int cost = 0;
        telefoane.forEach(telefon -> {
            if (telefon.getPret() > 5000)
                cost += telefon.getPret();
        });
        System.out.println(cost);
    }
}
