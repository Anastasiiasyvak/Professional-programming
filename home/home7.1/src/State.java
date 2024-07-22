public enum State {
    INTRO("Intro"),
    STARMAN("Starman"),
    SHOW_MUST_GO_ON("Show must go on"),
    LET_IT_BE("Let it be"),
    IN_THE_END("But in the end, it doesn't even matter");

    private final String song;

    State(String song) {
        this.song = song;
    }

    public String getSong() {
        return song;
    }
}
