# AI Log #2 — Design Comparison & Critique
## (Discussion Board)

**Unit 3: Custom Classes I**

**Format:** Canvas Discussion (Graded)

**Evaluation:** Mastery-Based (Mastered / Not Yet Mastered)

---

## Purpose

The purpose of this discussion is to help you develop critical judgment about software design, especially when working with AI tools. While AI can generate class designs quickly, professional programmers must decide whether those designs are clear, maintainable, correct, and appropriate for the problem context.

Research in computer science education shows that reflective comparison—rather than passive acceptance—leads to deeper conceptual understanding and stronger transfer of learning. This activity reinforces that **you are the designer, and AI is a tool**—not an authority.

This discussion also builds professional skills you will need in industry, where design decisions are routinely explained, justified, and reviewed by peers.

---

## Task

You will make **one initial discussion post** and **two peer responses**.

---

## Part A: Initial Post (Required)

After completing **Programming Assignment 1: ParkingMeter Class**, do the following:

1. Prompt an AI tool (e.g., ChatGPT, Claude, Copilot) to suggest a design for a `ParkingMeter` class with similar requirements.
2. Compare the AI-generated design to your own implementation.
3. Write a structured analysis post that addresses all sections below.

### Required Structure for Initial Post

Use headings or clearly labeled paragraphs.

#### 1. AI Prompt & Context
- What prompt did you give the AI?
- What was the AI asked to do?
- *(You do not need to paste the full AI response—summarize the design instead.)*

#### 2. Design Comparison
Compare your design and the AI's design in terms of:
- **Encapsulation** (data protection and access)
- **Constructors and object initialization**
- **Responsibilities of the class** (what the class should and should not do)
- **Validation logic** (how invalid inputs are handled)

#### 3. Critical Evaluation
Identify:
- **One design choice the AI handled well**
- **One design choice the AI handled poorly or unclearly**

**Explain why**—not just what.

#### 4. Your Design Decisions
Describe at least one decision you **intentionally kept, changed, or rejected** after seeing the AI output.

Be explicit about your reasoning.

#### 5. Reflection
Briefly reflect on:
- What this comparison taught you about object-oriented design
- How AI can be used responsibly in programming without replacing your thinking

---

## Part B: Peer Responses (Required)

You must respond to **at least two classmates**.

Each response must:
- Engage with a specific design decision mentioned in the post
- Ask a thoughtful question or offer a constructive alternative
- Go beyond agreement (e.g., "I agree") and add value to the discussion

### Examples of Strong Responses:

✓ "I noticed you rejected the AI's approach to coin validation—how might that affect extensibility if new coin types are added?"

✓ "Your reasoning about state management makes sense; did you consider what happens if `expire()` is called multiple times in a row?"

✓ "Interesting that the AI suggested storing all transactions. What are the trade-offs between that approach and just tracking `totalCollected_`?"

---

## Criteria for Success (Mastery-Based)

### Mastered

To earn **Mastered**, your discussion participation must include:

**An initial post that:**
- Clearly documents AI use (tool + prompt context)
- Compares AI and student designs meaningfully
- Demonstrates independent reasoning and judgment
- Critically evaluates AI output (strengths and weaknesses)

**Two substantive peer responses that:**
- Engage directly with design reasoning
- Contribute new insight or questions

**Professional tone and clear writing**

### Not Yet Mastered

A submission will be marked **Not Yet Mastered** if it:
- Lacks AI disclosure or prompt context
- Accepts AI output without critique
- Focuses only on surface-level differences (e.g., naming)
- Provides minimal or non-substantive peer responses
- Shows over-reliance on AI design decisions

**Revisions and make-ups follow the course token policy.**

---

## Why This Matters

In professional software development, design reviews are routine—and AI-generated suggestions are increasingly part of that process. This activity helps you practice:

- Explaining your design choices
- Evaluating alternatives critically
- Collaborating ethically with AI and peers

**These are professional competencies, not just academic skills.**

---

## Discussion Timeline (Recommended)

- **Initial Post Due:** Monday, 11:59 PM
- **Peer Responses Due:** Friday, 11:59 PM

---

## Tips for Success

✓ Focus on **design reasoning**, not just code mechanics

✓ Be honest about where AI helped—and where it did not

✓ Treat peer responses like a design review, not a comment section

✓ Reference specific examples from your code when making points

✓ Think about trade-offs: every design decision has advantages and disadvantages
