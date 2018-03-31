import matplotlib.pyplot as plt
import pandas as pd

PROJECT_VERSION = '0.1.0'


class StatsVisualizer:
    
    def __init__(self, file_path="out_stats.csv"):
        self.fig, self.ax = plt.subplots()
        self._file_path = file_path

    def draw_plot(self, x_var, y_var, _label="Figure 1"):
        """
        Creates plot: y_var = f(x_var). Doesn't draw it
        @param x_var: Variable of X axis
        @param y_var: Variable of Y axis
        @param _label: Label to graph
        @return: None
        """
        if x_var not in ['x', 'y', 'z', 'v_x', 'v_y', 'v_z', 'particle_number', 'iter_number']:
            raise ValueError("x_var is not in csv-file")
        if y_var not in ['x', 'y', 'z', 'v_x', 'v_y', 'v_z', 'particle_number', 'iter_number']:
            raise ValueError("y_var is not in csv-file")
        df = pd.read_csv(self._file_path)
        x = df.x_var
        y = df.y_var
        self.ax.plot(x_var, y_var)
        # Prettify plot
        if x_var == 'partcile_number':
            x_var = r'N'
        elif x_var == 'iter_number':
            x_var = r'Iteration'

        if y_var == 'partcile_number':
            y_var = r'N'
        elif y_var == 'iter_number':
            y_var = r'Iteration'

        self.ax.set_xlabel(x_var)
        self.ax.set_ylabel(y_var)
        self.ax.grid(True)
        self.ax.set_title(_label)

    def show_plot(self):
        self.fig.show()

    def save_plot(self, out_file="figure.pdf"):
        self.fig.savefig(out_file)