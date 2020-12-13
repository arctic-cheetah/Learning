
public class Organ {
    private String organ;
    private String medicalCondition;

    public Organ (String organ, String medicalCondition) {
        this.organ = organ;
        this.medicalCondition = medicalCondition;
    }
    public void setMedicalCondition(String medicalCondition) {
        this.medicalCondition = medicalCondition;
    }
    public String getMedicalCondition() {
        return medicalCondition;
    }
} 