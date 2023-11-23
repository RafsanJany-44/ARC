from tkinter import *
from tkinter import filedialog,messagebox
from tkinter import Label
from joblib import Parallel, delayed
import joblib
import pandas as pd
import sklearn
from sklearn.ensemble import _weight_boosting



def load_model(model_name):
    return joblib.load(model_name)



def model_call():
    
    data_path = path_entry.get()
    
    #data Reading
    df = pd.read_csv(data_path)
    
    y=df["Sleep_Stage"]
    
    X_test = df.loc[:,df.columns!="Sleep_Stage"]
    
    #model calling
    model_ada = load_model("Ada.sav")
    model_gb = load_model("Grad.sav")
    model_rf  = load_model("rf.sav")
    model_knn  = load_model("knn.sav")
    model_hb  = load_model("hb.sav")
    
    
    
    #prediction
    ada_pred = model_ada.predict(X_test)
    gb_pred  = model_gb.predict(X_test)
    rf_pred  = model_rf.predict(X_test)
    knn_pred  = model_knn.predict(X_test)
    hb_pred  = model_hb.predict(X_test)
    
    
    
    #sleep dictionary
    sleep_stage_dict = {0:"Deep Sleep", 1:"Light Sleep"}
    
    expected=0

    predicted_entry.delete(0, END)
    predicted_entry.insert(0, sleep_stage_dict[y[0]])
    ada_entry.delete(0, END)
    ada_entry.insert(0, sleep_stage_dict[ada_pred[0]])
    gb_entry.delete(0, END)
    gb_entry.insert(0, sleep_stage_dict[gb_pred[0]])
    knn_entry.delete(0, END)
    knn_entry.insert(0, sleep_stage_dict[knn_pred[0]])
    rf_entry.delete(0, END)
    rf_entry.insert(0, sleep_stage_dict[rf_pred[0]])
    hb_entry.delete(0, END)
    hb_entry.insert(0, sleep_stage_dict[hb_pred[0]])





root = Tk()
root.title("Sleep Stage Classification")
root.configure(bg="white")


# Label and Entry for Playlist URL
path_label = Label(root, text="Enter Data Path:")
path_label.grid(row=0, column=0, padx=5, pady=5, sticky="w")

path_entry = Entry(root, width=50)
path_entry.grid(row=1, column=0, padx=5, pady=5, sticky="w")

# Button to get playlist info
get_info_button = Button(root, text="Predict", command=model_call, padx=5, pady=2)
get_info_button.grid(row=1, column=1, padx=5, pady=5, sticky="w")

# Labels and Entries for Playlist Info
predicted_label = Label(root, text="Predicted Sleep Stage:")
predicted_label.grid(row=2, column=0, padx=5, pady=5, sticky="w")

predicted_entry = Entry(root, width=50)
predicted_entry.grid(row=3, column=0, padx=5, pady=5, sticky="w")


ada_label = Label(root, text="Ada Boosting:")
ada_label.grid(row=2, column=1, padx=5, pady=5, sticky="w")

ada_entry = Entry(root, width=10)
ada_entry.grid(row=3, column=1, padx=5, pady=5, sticky="w")

gb_label = Label(root, text="Gradient Boosting:")
gb_label.grid(row=2, column=2, padx=5, pady=5, sticky="w")

gb_entry = Entry(root, width=10)
gb_entry.grid(row=3, column=2, padx=5, pady=5, sticky="w")

knn_label = Label(root, text="KNN:")
knn_label.grid(row=2, column=3, padx=5, pady=5, sticky="w")

knn_entry = Entry(root, width=20)
knn_entry.grid(row=3, column=3, padx=5, pady=5, sticky="w")

rf_label = Label(root, text="Random Forest:")
rf_label.grid(row=4, column=1, padx=5, pady=5, sticky="w")

rf_entry = Entry(root, width=10)
rf_entry.grid(row=5, column=1, padx=5, pady=5, sticky="w")

hb_label = Label(root, text="Histogram Boosting:")
hb_label.grid(row=4, column=2, padx=5, pady=5, sticky="w")

hb_entry = Entry(root, width=10)
hb_entry.grid(row=5, column=2, padx=5, pady=5, sticky="w")

root.mainloop()