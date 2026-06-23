```sql
-- ============================================
-- BankCoreCPP PostgreSQL Schema
-- ============================================

DROP TABLE IF EXISTS audit_log CASCADE;
DROP TABLE IF EXISTS transactions CASCADE;
DROP TABLE IF EXISTS accounts CASCADE;
DROP TABLE IF EXISTS customers CASCADE;

-- ============================================
-- CUSTOMERS
-- ============================================

CREATE TABLE customers
(
    customer_id SERIAL PRIMARY KEY,

    first_name VARCHAR(100) NOT NULL,

    last_name VARCHAR(100) NOT NULL,

    passport_number VARCHAR(50)
        UNIQUE NOT NULL,

    phone VARCHAR(30),

    email VARCHAR(100),

    created_at TIMESTAMP
        DEFAULT CURRENT_TIMESTAMP
);

-- ============================================
-- ACCOUNTS
-- ============================================

CREATE TABLE accounts
(
    account_id SERIAL PRIMARY KEY,

    customer_id INTEGER NOT NULL,

    account_number VARCHAR(30)
        UNIQUE NOT NULL,

    balance NUMERIC(15,2)
        DEFAULT 0.00
        CHECK (balance >= 0),

    currency VARCHAR(3)
        DEFAULT 'EUR'
        CHECK (currency IN ('EUR','USD','GBP')),

    status VARCHAR(20)
        DEFAULT 'ACTIVE'
        CHECK (status IN
              ('ACTIVE',
               'BLOCKED',
               'CLOSED')),

    created_at TIMESTAMP
        DEFAULT CURRENT_TIMESTAMP,

    CONSTRAINT fk_customer
        FOREIGN KEY(customer_id)
        REFERENCES customers(customer_id)
        ON DELETE CASCADE
);

-- ============================================
-- TRANSACTIONS
-- ============================================

CREATE TABLE transactions
(
    transaction_id SERIAL PRIMARY KEY,

    from_account INTEGER,

    to_account INTEGER,

    amount NUMERIC(15,2)
        NOT NULL
        CHECK (amount > 0),

    operation_type VARCHAR(20)
        NOT NULL
        CHECK (operation_type IN
              ('DEPOSIT',
               'WITHDRAW',
               'TRANSFER')),

    transaction_time TIMESTAMP
        DEFAULT CURRENT_TIMESTAMP,

    description TEXT,

    CONSTRAINT fk_from_account
        FOREIGN KEY(from_account)
        REFERENCES accounts(account_id),

    CONSTRAINT fk_to_account
        FOREIGN KEY(to_account)
        REFERENCES accounts(account_id)
);

-- ============================================
-- AUDIT LOG
-- ============================================

CREATE TABLE audit_log
(
    log_id SERIAL PRIMARY KEY,

    username VARCHAR(50) NOT NULL,

    operation VARCHAR(255) NOT NULL,

    event_time TIMESTAMP
        DEFAULT CURRENT_TIMESTAMP
);

-- ============================================
-- INDEXES
-- ============================================

CREATE INDEX idx_customer_last_name
ON customers(last_name);

CREATE INDEX idx_account_number
ON accounts(account_number);

CREATE INDEX idx_transaction_time
ON transactions(transaction_time);

CREATE INDEX idx_audit_time
ON audit_log(event_time);

-- ============================================
-- TEST DATA
-- ============================================

INSERT INTO customers
(first_name,
 last_name,
 passport_number,
 phone,
 email)
VALUES
('John',
 'Smith',
 'AA123456',
 '+49111111111',
 'john.smith@mail.com'),

('Maria',
 'Muller',
 'BB987654',
 '+49222222222',
 'maria.muller@mail.com');

INSERT INTO accounts
(customer_id,
 account_number,
 balance,
 currency)
VALUES
(1,
 'DE1000000001',
 5000.00,
 'EUR'),

(2,
 'DE1000000002',
 3000.00,
 'EUR');

INSERT INTO transactions
(from_account,
 to_account,
 amount,
 operation_type,
 description)
VALUES
(1,
 2,
 500.00,
 'TRANSFER',
 'Initial transfer');
```
