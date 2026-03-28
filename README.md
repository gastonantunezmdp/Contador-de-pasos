# Sistema de Conteo y Control Automático para Maquinaria Textil

## Descripción de la Solución

Sistema de control electrónico diseñado para modernizar y automatizar procesos de conteo en maquinaria industrial textil. Esta solución está desarrollada específicamente para reemplazar sistemas mecánicos obsoletos, como **relojes contadores manuales**, por una tecnología precisa, confiable y de bajo mantenimiento que optimiza la producción y reduce errores humanos.

## Problema Resuelto

La máquina tenía un sistema muy antiguo y roto, un reloj mecánico que avanzaba un número cada vez que el carro llegaba al final de su recorrido. El problema era que **no era confiable** y la forma de detener el proceso era **manual** cuando se alcanzaba la cantidad de prendas deseada.

## Funcionalidades

- **Configuración flexible** del número de ciclos deseados
- **Conteo automático** cada vez que el carro completa su recorrido
- **Detención automática** de la máquina mediante embrague electromecánico
- **Visualización en tiempo real** del progreso y estado del sistema
- **Reset automático** para comenzar nuevos lotes de producción

## Especificaciones Técnicas

| Componente | Especificación |
|------------|----------------|
| **Microcontrolador** | ESP8266 (NodeMCU) |
| **Display** | LCD 16x2 con interfaz I2C |
| **Alimentación** | 5V DC |
| **Rango de conteo** | 0-32767 ciclos |
| **Precisión** | 100% (detección digital) |
| **Tiempo de respuesta** | < 200ms |
| **Temperatura de operación** | 0°C a 70°C |

## Instalación e Implementación

- **Espacio mínimo en panel de control**: 15cm x 10cm x 5cm
- **Acceso a alimentación de red** (220v)
- **Posibilidad de montar sensor de final de carrera** en el recorrido del carro
- **Acceso al mecanismo de embrague** para instalación del servomotor
