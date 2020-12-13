
class Stomach extends Organ {
    private String status;
    public Stomach (String organ, String medicalCondition, String status) {
        super(organ, medicalCondition);
        this.status = status;
    }

    public void setStatus(String status) {
        this.status = status;
    }
    public String getStatus() {
        return status;
    }
}