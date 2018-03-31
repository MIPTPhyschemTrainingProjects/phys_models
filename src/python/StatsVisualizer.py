import matplotlib.pyplot as plt
import pandas as pd

PROJECT_VERSION = '0.1.0'


class StatsVisualizer:

    df_columns = ['x', 'y', 'z', 'v_x', 'v_y', 'v_z', 'particle_number', 'iter_number']
    
    def __init__(self, file_path="out_stats.csv"):
        self.fig, self.ax = plt.subplots()
        self._file_path = file_path
        self.df = pd.read_csv(file_path)

    def _get_column(self, col_name, particle_no):
        """
        Gets Series column for one particle
        @param particle_no: Number of particle
        @param col_name: Name of column
        @return: Pandas Series object with column
        """
        return self.df[col_name][self.df.particle_number == particle_no]

    def create_plot(self, x_var, y_var, particle_number,  _label="Figure 1"):
        """
        Creates plot: y_var = f(x_var). Doesn't draw it
        @param x_var: Variable of X axis
        @param y_var: Variable of Y axis
        @param particle_number: Number of particle to track
        @param _label: Label to graph
        @return: None
        """
        if x_var not in self.df_columns:
            raise ValueError("x_var is not in csv-file")
        if y_var not in self.df_columns:
            raise ValueError("y_var is not in csv-file")
        x = self._get_column(x_var, particle_number)
        y = self._get_column(y_var, particle_number)
        self.ax.plot(x, y)
        # Prettify plot
        self.ax.set_xlabel(x_var)
        self.ax.set_ylabel(y_var)
        self.ax.grid(True)
        self.ax.set_title(_label)

    def show_plot(self):
        self.fig.show()

    def save_plot(self, out_file="figure.pdf"):
        self.fig.savefig(out_file)