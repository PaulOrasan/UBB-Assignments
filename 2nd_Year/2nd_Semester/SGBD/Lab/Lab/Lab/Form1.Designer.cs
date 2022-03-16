
namespace Lab
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.circuitDataGridView = new System.Windows.Forms.DataGridView();
            this.iDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.numeDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.circuitBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tenisDataSet = new Lab.TenisDataSet();
            this.tariBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tariTableAdapter = new Lab.TenisDataSetTableAdapters.TariTableAdapter();
            this.circuitTableAdapter = new Lab.TenisDataSetTableAdapters.CircuitTableAdapter();
            this.tipTurneuDataGridView = new System.Windows.Forms.DataGridView();
            this.iDDataGridViewTextBoxColumn1 = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.titluDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.puncteDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.premiuDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.circuitIDDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.fKTipTurneuCircu286302ECBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.fKTurneuTipID2F10007BBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tipTurneuBindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.tipTurneuBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tipTurneuTableAdapter = new Lab.TenisDataSetTableAdapters.TipTurneuTableAdapter();
            this.turneuTableAdapter = new Lab.TenisDataSetTableAdapters.TurneuTableAdapter();
            this.fKTipTurneuCircu286302ECBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.tipTurneuBindingSource2 = new System.Windows.Forms.BindingSource(this.components);
            this.saveButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.circuitDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.circuitBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tenisDataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tariBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tipTurneuDataGridView)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTipTurneuCircu286302ECBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTurneuTipID2F10007BBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tipTurneuBindingSource1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tipTurneuBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTipTurneuCircu286302ECBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.tipTurneuBindingSource2)).BeginInit();
            this.SuspendLayout();
            // 
            // circuitDataGridView
            // 
            this.circuitDataGridView.AutoGenerateColumns = false;
            this.circuitDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.circuitDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.iDDataGridViewTextBoxColumn,
            this.numeDataGridViewTextBoxColumn});
            this.circuitDataGridView.DataSource = this.circuitBindingSource;
            this.circuitDataGridView.Location = new System.Drawing.Point(28, 40);
            this.circuitDataGridView.Name = "circuitDataGridView";
            this.circuitDataGridView.RowHeadersWidth = 51;
            this.circuitDataGridView.RowTemplate.Height = 24;
            this.circuitDataGridView.Size = new System.Drawing.Size(588, 171);
            this.circuitDataGridView.TabIndex = 0;
            // 
            // iDDataGridViewTextBoxColumn
            // 
            this.iDDataGridViewTextBoxColumn.DataPropertyName = "ID";
            this.iDDataGridViewTextBoxColumn.HeaderText = "ID";
            this.iDDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.iDDataGridViewTextBoxColumn.Name = "iDDataGridViewTextBoxColumn";
            this.iDDataGridViewTextBoxColumn.ReadOnly = true;
            this.iDDataGridViewTextBoxColumn.Width = 125;
            // 
            // numeDataGridViewTextBoxColumn
            // 
            this.numeDataGridViewTextBoxColumn.DataPropertyName = "Nume";
            this.numeDataGridViewTextBoxColumn.HeaderText = "Nume";
            this.numeDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.numeDataGridViewTextBoxColumn.Name = "numeDataGridViewTextBoxColumn";
            this.numeDataGridViewTextBoxColumn.Width = 125;
            // 
            // circuitBindingSource
            // 
            this.circuitBindingSource.DataMember = "Circuit";
            this.circuitBindingSource.DataSource = this.tenisDataSet;
            // 
            // tenisDataSet
            // 
            this.tenisDataSet.DataSetName = "TenisDataSet";
            this.tenisDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // tariBindingSource
            // 
            this.tariBindingSource.DataMember = "Tari";
            this.tariBindingSource.DataSource = this.tenisDataSet;
            // 
            // tariTableAdapter
            // 
            this.tariTableAdapter.ClearBeforeFill = true;
            // 
            // circuitTableAdapter
            // 
            this.circuitTableAdapter.ClearBeforeFill = true;
            // 
            // tipTurneuDataGridView
            // 
            this.tipTurneuDataGridView.AutoGenerateColumns = false;
            this.tipTurneuDataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.tipTurneuDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.iDDataGridViewTextBoxColumn1,
            this.titluDataGridViewTextBoxColumn,
            this.puncteDataGridViewTextBoxColumn,
            this.premiuDataGridViewTextBoxColumn,
            this.circuitIDDataGridViewTextBoxColumn});
            this.tipTurneuDataGridView.DataSource = this.fKTipTurneuCircu286302ECBindingSource1;
            this.tipTurneuDataGridView.Location = new System.Drawing.Point(12, 296);
            this.tipTurneuDataGridView.Name = "tipTurneuDataGridView";
            this.tipTurneuDataGridView.RowHeadersWidth = 51;
            this.tipTurneuDataGridView.RowTemplate.Height = 24;
            this.tipTurneuDataGridView.Size = new System.Drawing.Size(776, 142);
            this.tipTurneuDataGridView.TabIndex = 1;
            // 
            // iDDataGridViewTextBoxColumn1
            // 
            this.iDDataGridViewTextBoxColumn1.DataPropertyName = "ID";
            this.iDDataGridViewTextBoxColumn1.HeaderText = "ID";
            this.iDDataGridViewTextBoxColumn1.MinimumWidth = 6;
            this.iDDataGridViewTextBoxColumn1.Name = "iDDataGridViewTextBoxColumn1";
            this.iDDataGridViewTextBoxColumn1.ReadOnly = true;
            this.iDDataGridViewTextBoxColumn1.Width = 125;
            // 
            // titluDataGridViewTextBoxColumn
            // 
            this.titluDataGridViewTextBoxColumn.DataPropertyName = "Titlu";
            this.titluDataGridViewTextBoxColumn.HeaderText = "Titlu";
            this.titluDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.titluDataGridViewTextBoxColumn.Name = "titluDataGridViewTextBoxColumn";
            this.titluDataGridViewTextBoxColumn.Width = 125;
            // 
            // puncteDataGridViewTextBoxColumn
            // 
            this.puncteDataGridViewTextBoxColumn.DataPropertyName = "Puncte";
            this.puncteDataGridViewTextBoxColumn.HeaderText = "Puncte";
            this.puncteDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.puncteDataGridViewTextBoxColumn.Name = "puncteDataGridViewTextBoxColumn";
            this.puncteDataGridViewTextBoxColumn.Width = 125;
            // 
            // premiuDataGridViewTextBoxColumn
            // 
            this.premiuDataGridViewTextBoxColumn.DataPropertyName = "Premiu";
            this.premiuDataGridViewTextBoxColumn.HeaderText = "Premiu";
            this.premiuDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.premiuDataGridViewTextBoxColumn.Name = "premiuDataGridViewTextBoxColumn";
            this.premiuDataGridViewTextBoxColumn.Width = 125;
            // 
            // circuitIDDataGridViewTextBoxColumn
            // 
            this.circuitIDDataGridViewTextBoxColumn.DataPropertyName = "CircuitID";
            this.circuitIDDataGridViewTextBoxColumn.HeaderText = "CircuitID";
            this.circuitIDDataGridViewTextBoxColumn.MinimumWidth = 6;
            this.circuitIDDataGridViewTextBoxColumn.Name = "circuitIDDataGridViewTextBoxColumn";
            this.circuitIDDataGridViewTextBoxColumn.Width = 125;
            // 
            // fKTipTurneuCircu286302ECBindingSource1
            // 
            this.fKTipTurneuCircu286302ECBindingSource1.DataMember = "FK__TipTurneu__Circu__286302EC";
            this.fKTipTurneuCircu286302ECBindingSource1.DataSource = this.circuitBindingSource;
            // 
            // fKTurneuTipID2F10007BBindingSource
            // 
            this.fKTurneuTipID2F10007BBindingSource.DataMember = "FK__Turneu__TipID__2F10007B";
            this.fKTurneuTipID2F10007BBindingSource.DataSource = this.tipTurneuBindingSource1;
            // 
            // tipTurneuBindingSource1
            // 
            this.tipTurneuBindingSource1.DataMember = "TipTurneu";
            this.tipTurneuBindingSource1.DataSource = this.tenisDataSet;
            // 
            // tipTurneuBindingSource
            // 
            this.tipTurneuBindingSource.DataMember = "TipTurneu";
            this.tipTurneuBindingSource.DataSource = this.tenisDataSet;
            // 
            // tipTurneuTableAdapter
            // 
            this.tipTurneuTableAdapter.ClearBeforeFill = true;
            // 
            // turneuTableAdapter
            // 
            this.turneuTableAdapter.ClearBeforeFill = true;
            // 
            // fKTipTurneuCircu286302ECBindingSource
            // 
            this.fKTipTurneuCircu286302ECBindingSource.DataMember = "FK__TipTurneu__Circu__286302EC";
            this.fKTipTurneuCircu286302ECBindingSource.DataSource = this.circuitBindingSource;
            // 
            // tipTurneuBindingSource2
            // 
            this.tipTurneuBindingSource2.DataMember = "TipTurneu";
            this.tipTurneuBindingSource2.DataSource = this.tenisDataSet;
            // 
            // saveButton
            // 
            this.saveButton.Location = new System.Drawing.Point(675, 84);
            this.saveButton.Name = "saveButton";
            this.saveButton.Size = new System.Drawing.Size(113, 23);
            this.saveButton.TabIndex = 2;
            this.saveButton.Text = "Save changes!";
            this.saveButton.UseVisualStyleBackColor = true;
            this.saveButton.Click += new System.EventHandler(this.saveButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.saveButton);
            this.Controls.Add(this.tipTurneuDataGridView);
            this.Controls.Add(this.circuitDataGridView);
            this.Name = "Form1";
            this.Text = "Form1";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.circuitDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.circuitBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tenisDataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tariBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tipTurneuDataGridView)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTipTurneuCircu286302ECBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTurneuTipID2F10007BBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tipTurneuBindingSource1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tipTurneuBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.fKTipTurneuCircu286302ECBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.tipTurneuBindingSource2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView circuitDataGridView;
        private TenisDataSet tenisDataSet;
        private System.Windows.Forms.BindingSource tariBindingSource;
        private TenisDataSetTableAdapters.TariTableAdapter tariTableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn iDDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn numeDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource circuitBindingSource;
        private TenisDataSetTableAdapters.CircuitTableAdapter circuitTableAdapter;
        private System.Windows.Forms.DataGridView tipTurneuDataGridView;
        private System.Windows.Forms.BindingSource tipTurneuBindingSource;
        private TenisDataSetTableAdapters.TipTurneuTableAdapter tipTurneuTableAdapter;
        private System.Windows.Forms.BindingSource tipTurneuBindingSource1;
        private System.Windows.Forms.BindingSource fKTurneuTipID2F10007BBindingSource;
        private TenisDataSetTableAdapters.TurneuTableAdapter turneuTableAdapter;
        private System.Windows.Forms.BindingSource fKTipTurneuCircu286302ECBindingSource1;
        private System.Windows.Forms.BindingSource fKTipTurneuCircu286302ECBindingSource;
        private System.Windows.Forms.BindingSource tipTurneuBindingSource2;
        private System.Windows.Forms.Button saveButton;
        private System.Windows.Forms.DataGridViewTextBoxColumn iDDataGridViewTextBoxColumn1;
        private System.Windows.Forms.DataGridViewTextBoxColumn titluDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn puncteDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn premiuDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn circuitIDDataGridViewTextBoxColumn;
    }
}

