package com.example.controller;


import com.example.domain.Nota;
import com.example.domain.NotaDto;
import com.example.service.ServiceManager;
import javafx.collections.FXCollections;
import javafx.collections.ListChangeListener;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.util.Callback;


import java.time.LocalDate;
import java.util.List;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class NotaController {

    ObservableList<NotaDto> modelGrade = FXCollections.observableArrayList();
    List<String> modelTema;
    private ServiceManager service;


    @FXML
    TableColumn<NotaDto, String> tableColumnName;
    @FXML
    TableColumn<NotaDto, String> tableColumnTema;
    @FXML
    TableColumn<NotaDto, Double> tableColumnNota;
    @FXML
    TableColumn<NotaDto, LocalDate> tableColumnData;
    @FXML
    TableView<NotaDto> tableViewNote;
    //----------------------end TableView fx:id----------------

    @FXML
    TextField textFieldName;
    @FXML
    TextField textFieldTema;
    @FXML
    TextField textFieldNota;

    @FXML
    ComboBox<String> comboBoxTeme;

    @FXML
    DatePicker datePicker;

    @FXML
    public void initialize() {
        tableColumnName.setCellValueFactory(new PropertyValueFactory<NotaDto, String>("studentName"));
        tableColumnTema.setCellValueFactory(new PropertyValueFactory<NotaDto, String>("temaId"));
        tableColumnNota.setCellValueFactory(new PropertyValueFactory<NotaDto, Double>("nota"));
        tableColumnData.setCellValueFactory(new PropertyValueFactory<NotaDto, LocalDate>("date"));

        tableViewNote.setItems(modelGrade);

        textFieldName.textProperty().addListener(o -> handleFilter());
        textFieldTema.textProperty().addListener(o -> handleFilter());
        textFieldNota.textProperty().addListener(o -> handleFilter());

        comboBoxTeme.getSelectionModel().selectedItemProperty().addListener(
                (x,y,z)->handleFilter()
        );

        datePicker.valueProperty().addListener(
                e -> handleFilter()
        );



    }

    private List<NotaDto> getNotaDTOList() {
        return service.findAllGrades()
                .stream()
                .map(n -> new NotaDto(n.getStudent().getName(), n.getTema().getId(), n.getValue(), n.getProfesor(), n.getDate()))
                .collect(Collectors.toList());
    }

    private void handleFilter() {
        Predicate<NotaDto> p1 = n -> n.getStudentName().startsWith(textFieldName.getText());
        Predicate<NotaDto> p2 = n -> n.getTemaId().startsWith(textFieldTema.getText());
        Predicate<NotaDto> p3 = n -> {
            try {
                return n.getNota() > Double.parseDouble(textFieldNota.getText());
            } catch (NumberFormatException ex) {
                return true;
            }
        };

        Predicate<NotaDto> p4 = n -> n.getTemaId().equals(comboBoxTeme.getSelectionModel().getSelectedItem());
        Predicate<NotaDto> p5 = n -> datePicker.getValue() == null || n.getDate().isEqual(datePicker.getValue()) ||
                    n.getDate().isAfter(datePicker.getValue());

        modelGrade.setAll(getNotaDTOList()
                .stream()
                .filter(p1.and(p2).and(p3).and(p4).and(p5))
                .collect(Collectors.toList()));
    }


    public void setService(ServiceManager service) {
        this.service = service;
        modelGrade.setAll(getNotaDTOList());
        modelTema = service.findAllHomeWorks()
                .stream()
                .map(x -> x.getId())
                .collect(Collectors.toList());
        comboBoxTeme.getItems().setAll(modelTema);
        comboBoxTeme.getSelectionModel().selectFirst();
    }
}
