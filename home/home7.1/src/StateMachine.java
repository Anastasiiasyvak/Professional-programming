import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class StateMachine {
    private State currentState;

    private final Map<State, Map<String, State>> transitions;

    public StateMachine() {
        currentState = State.INTRO;
        transitions = new HashMap<>();
        setupTransitions();
    }

    private void setupTransitions() {
        transitions.put(State.INTRO, new HashMap<>() {{
            put("dangerous", State.LET_IT_BE);
            put("fun", State.STARMAN);
            put("sad", State.IN_THE_END);
        }});

        transitions.put(State.STARMAN, new HashMap<>() {{
            put("silly", State.INTRO);
            put("dangerous", State.SHOW_MUST_GO_ON);
            put("fun", State.IN_THE_END);
        }});

        transitions.put(State.SHOW_MUST_GO_ON, new HashMap<>() {{
            put("sad", State.LET_IT_BE);
            put("fun", State.STARMAN);
        }});

        transitions.put(State.LET_IT_BE, new HashMap<>() {{
            put("dangerous", State.INTRO);
            put("silly", State.SHOW_MUST_GO_ON);
        }});
    }

    public void start() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            System.out.println("Current song: " + currentState.getSong());
            System.out.print("Enter command (sad, fun, silly, dangerous): ");
            String command = scanner.nextLine();

            if (transitions.get(currentState).containsKey(command)) {
                currentState = transitions.get(currentState).get(command);
                if (currentState == State.IN_THE_END) {
                    System.out.println("Current song: " + currentState.getSong());
                    System.out.println("Program terminated.");
                    break;
                }
            } else {
                System.out.println("Replaying current song.");
            }
        }
        scanner.close();
    }
}
