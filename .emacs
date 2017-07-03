(package-initialize)

(set-default 'cursor-type '(hbar . 3))

(require 'auto-complete)

(require 'auto-complete-config)

(ac-config-default)

(require 'yasnippet)

(yas-global-mode 1)

(define-key global-map (kbd "C-c ;") 'iedit-mode)

(global-flycheck-mode 1)

(global-linum-mode 1)

(setq mouse-wheel-scroll-amount '(1 ((shift) . 1)))
    
(setq mouse-wheel-progressive-speed nil)

(setq mouse-wheel-follow-mouse 't)
    
(setq scroll-step 1)

(electric-pair-mode 1)
