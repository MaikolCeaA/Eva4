package com.example.arduino
import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import com.google.firebase.database.*

class MainActivity : AppCompatActivity() {

    private lateinit var textViewDistancia: TextView
    private lateinit var databaseReference: DatabaseReference

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        textViewDistancia = findViewById(R.id.textView)

        // Obtén la referencia de la base de datos
        databaseReference = FirebaseDatabase.getInstance().reference.child("datos").child("Distancia")

        // Agrega un listener para leer cambios en la base de datos
        databaseReference.addValueEventListener(object : ValueEventListener {
            override fun onDataChange(dataSnapshot: DataSnapshot) {
                if (dataSnapshot.exists()) {
                    // Obtén el valor de la base de datos y actualiza la interfaz de usuario
                    val distancia = dataSnapshot.child("Distancia").value.toString()
                    textViewDistancia.text = " $distancia"
                } else {
                    // Maneja el caso en el que no existan datos
                    textViewDistancia.text = "No hay datos disponibles"
                }
            }

            override fun onCancelled(databaseError: DatabaseError) {
                // Maneja errores de lectura de la base de datos
            }
        })
    }
}