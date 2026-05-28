# OOP Assignment — GitHub Setup Report

## Step 1: GitHub Account

I already had a GitHub account with the username **Nguynie**. No new account was needed.

## Step 2: Create the Repository

I used the GitHub CLI (`gh`) to create a personal, private repository:

```
gh repo create Nguynie/OOP-Assignment --private --add-readme
```

The repo was created at `https://github.com/Nguynie/OOP-Assignment`.

## Step 3: Clone the Repository Locally

```
gh repo clone Nguynie/OOP-Assignment
```

This cloned the (currently empty except for the auto-generated README) repository to my local machine.

## Step 4: Write This Report

I created this Markdown file (`OOP-Assignment-Report.md`) to document the process.

## Step 5: Commit and Push

```
cd OOP-Assignment
git add OOP-Assignment-Report.md
git commit -m "Add assignment setup report"
git push
```

## Step 6: Verify

After pushing, I confirmed the report appears on the remote repository by viewing it:

```
gh repo view Nguynie/OOP-Assignment
```

---

**Final result:** A private GitHub repository `Nguynie/OOP-Assignment` is set up and ready for use throughout the course.
