# Budget/Expense Tracker

This is an application that is designed for creating a budget and tracking expenses. It is built for those who like to keep track 
of their monthly expense and maintain their allotted budget.  

> **Status:** Work in progress.
Right now the only working portion is the core logic that is backed by the native unit testing. 

## Overview

This a program is designed to be used as a personal budgeting and expense tracker, that organizes spending into monthly budget periods and categories. The core logic is written in C++ with SQLite for storage. 
I originally studied Finances and because of that, I have always made sure that I maintained a monthly budget and tracked my spending for the month. 
However, I never liked any of the well known apps or programs for doing so and ended up doing it by hand. So, as my first major project, I wanted to build something that I could use 
in my everyday life and structure it to my preferences. The project started as a simple command-line program. I'm now restructuring it into a full-stack application that I plan to host on a local home server.

## Features

**Currently working**
- Core Budgeting logic (Expenses, Categories, Budget Periods and Budget Manager)
- Guard checks that protect invalid states and duplicate entry of unique values
- Unit tests that cover the core logic

**In progress**
- SQLite database integration
- Front end
- Front end/back end API connection
- Server hosting


## Architecture

The core logic of the program is written in C++ and uses SQLite for storage. A front end will eventually connect 
to it through an API, and the whole project will be hosted on a server so that I may access it through any device. 

| Layer | Technology | Notes |
|-------|------------|-------|
| Core logic | C++ | Expense, Category, BudgetManager, BudgetPeriod, etc. |
| Database | SQLite (via SQLiteCpp) | Source of truth; in-memory vectors act as a synced working copy |
| API | TBD | Still needs to be determined |
| Front end | TBD | Still needs to be determined |
| Hosting | Ubuntu Server | Still need to look into my options |

### Database Schema

- **BudgetPeriod**: id, month, year, income
- **Category**: id, budget_period_id, name, amount
- **Expense**: id, category_id, name, price, date, description

## Roadmap

### In Progress
- [ ] SQLite database integration
- [ ] Front end
- [ ] Front end / back end API connection
- [ ] Server hosting

### Next: Foundations
- [ ] Input validation wired into all classes
- [ ] Editing existing data (expenses, categories, period income)
- [ ] Consistent error handling and API error responses
- [ ] Authentication
- [ ] HTTPS
- [ ] Database backups

### Then: Features
- [ ] Budget vs. actual reporting
- [ ] Search and filtering
- [ ] Recurring expenses
- [ ] CSV export/import

### Later: Polish
- [ ] Charts and spending summaries
- [ ] Spending alerts
- [ ] Mobile UI polish

### Ongoing
- [ ] Expanded test coverage
- [ ] CI (build and test on every push)
- [ ] Setup and usage documentation

