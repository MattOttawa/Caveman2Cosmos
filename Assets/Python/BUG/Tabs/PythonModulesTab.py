import BugOptionsTab
import ModuleMgr

class PythonModulesTab(BugOptionsTab.BugOptionsTab):

	def __init__(self):
		BugOptionsTab.BugOptionsTab.__init__(self, "PythonModules", "Python Modules")

	def create(self, screen):
		self.createTab(screen)
		panel = self.createMainPanel(screen)
		column = self.addOneColumnLayout(screen, panel)
		left, right = self.addTwoColumnLayout(screen, column, "Modules", True)
		column = left
		Parser = ModuleMgr.readIniFile()
		for module, value in Parser.items("MODULES"):
			control = module + "Check"
			screen.attachCheckBox(column, control, module, "BUG_OptionsCB_IF", "handlePythonModuleChange", module, bool(value))
			#screen.setToolTip(control, module)
			if column is left:
				column = right
			else:
				column = left