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

---

# OOP Assignment — GitHub Pages Setup Report

## Step 1: Create a Resume Page

I created a `docs/` directory in the repository and added `docs/index.md` — a Markdown resume skeleton with sections for Education, Skills, Projects, Experience, and Contact. The content is a template ready to be filled in later.

```
mkdir -p docs
```

File: [`docs/index.md`](docs/index.md)

## Step 2: Enable GitHub Pages

The repository was initially private. GitHub Free only supports Pages on public repositories, so I changed the visibility to public:

```
gh repo edit Nguynie/OOP-Assignment --visibility public --accept-visibility-change-consequences
```

Then I enabled GitHub Pages via the API, serving from the `main` branch, `/docs` folder:

```
gh api repos/Nguynie/OOP-Assignment/pages \
  -X POST \
  -f source[branch]=main \
  -f source[path]=/docs
```

## Step 3: Push and Verify

I committed and pushed the `docs/` folder, then waited for the Pages deployment to complete. The site became available at:

**https://nguynie.github.io/OOP-Assignment/**

A quick `curl` confirmed the site returns HTTP 200 and the resume content renders correctly.

## Step 4: Final Verification

- **Repository:** `https://github.com/Nguynie/OOP-Assignment` (now public)
- **Pages URL:** `https://nguynie.github.io/OOP-Assignment/`
- **Status:** Live, serving the resume from `docs/index.md`

---

**Final result:** A GitHub Pages site is live at `https://nguynie.github.io/OOP-Assignment/` hosting a resume page, ready to be updated throughout the course.
