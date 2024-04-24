public class static void main() {



}

public class Player {

    String name;
    int MaxLife;
    Attack attack01 = new Attack("Tapinha", 5, 10);
    Attack attack02 = new Attack("Voadora de 3 pernas", 10, 6);
    Attack attack03 = new Attack("ofensa do mudo", 99999, -10);
    Attack attack04;

    Player(String name, int maxfife){

    }
}

public class Attack {

    String name;
    int MaxDamage;
    int MaxUsages;

    Attack(String name,
           int MaxDamage,
           int MaxUsages)
    {

        this.name = name;
        this.MaxDamage = MaxDamage;
        this.MaxUsages = MaxUsages;


    }
}
