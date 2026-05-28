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
