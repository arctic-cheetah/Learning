
public class RightEye extends Organ {
    private static int test;
    private String colour;
    private String action = "Eye closed";

    public RightEye(String organ, String medicalCondition, String colour) {
        super(organ, medicalCondition);
        this.colour = colour;
    }

    public void setColour(String colour) {
        this.colour = colour;
    }
    public String getColour() {
        return colour;
    }

    public void setAction(String action) {
        this.action = action;
    }
    public String getAction() {
        return action;
    }

}