public class OrangeMessage {
    private String message1;
    private String message2;
    private int number;
    private double value;

    public OrangeMessage(String message1, String message2, int number, double value) {
        this.message1 = message1;
        this.message2 = message2;
        this.number = number;
        this.value = value;
    }

    public String getMessage1() {
        return message1;
    }

    public String getMessage2() {
        return message2;
    }

    public int getNumber() {
        return number;
    }

    public double getValue() {
        return value;
    }
}
