
public class Heart extends Organ {
    private int heartRate;

    public Heart (String organ, String medicalCondition, int heartRate) {
        super(organ, medicalCondition);
        this.heartRate = heartRate;
    }

    public void setHeartRate(int heartRate) {
        this.heartRate = heartRate;
    }
    public int getHeartRate() {
        return heartRate;
    }

}