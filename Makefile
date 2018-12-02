.PHONY: clean All

All:
	@echo "----------Building project:[ Udacity_PID-P4 - Debug ]----------"
	@"$(MAKE)" -f  "Udacity_PID-P4.mk"
clean:
	@echo "----------Cleaning project:[ Udacity_PID-P4 - Debug ]----------"
	@"$(MAKE)" -f  "Udacity_PID-P4.mk" clean
