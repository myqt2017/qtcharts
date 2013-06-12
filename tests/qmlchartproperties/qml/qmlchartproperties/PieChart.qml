/****************************************************************************
**
** Copyright (C) 2013 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Enterprise Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Enterprise licenses may use this file in
** accordance with the Qt Enterprise License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 1.0
import QtCommercial.Chart 1.1

ChartView {
    id: chart
    title: "pie series"
    animationOptions: ChartView.SeriesAnimations

    property variant series: pieSeries

    PieSeries {
        id: pieSeries
        name: "pie"
        PieSlice { label: "slice1"; value: 11;
            onValueChanged:         console.log("slice.onValueChanged: " + value);
            onLabelVisibleChanged:  console.log("slice.onLabelVisibleChanged: " + labelVisible);
            onPenChanged:           console.log("slice.onPenChanged: " + pen);
            onBorderColorChanged:   console.log("slice.onBorderColorChanged: " + borderColor);
            onBorderWidthChanged:   console.log("slice.onBorderWidthChanged: " + borderWidth);
            onBrushChanged:         console.log("slice.onBrushChanged: " + brush);
            onColorChanged:         console.log("slice.onColorChanged: " + color);
            onLabelColorChanged:    console.log("slice.onLabelColorChanged: " + labelColor);
            onLabelBrushChanged:    console.log("slice.onLabelBrushChanged: " + labelBrush);
            onLabelFontChanged:     console.log("slice.onLabelFontChanged: " + labelFont);
            onPercentageChanged:    console.log("slice.onPercentageChanged: " + percentage);
            onStartAngleChanged:    console.log("slice.onStartAngleChanged: " + startAngle);
            onAngleSpanChanged:     console.log("slice.onAngleSpanChanged: " + angleSpan);
            onClicked:              console.log("slice.onClicked: " + label);
            onHovered:              console.log("slice.onHovered: " + state);
        }
        PieSlice { label: "slice2"; value: 22 }
        PieSlice { label: "slice3"; value: 33 }
        PieSlice { label: "slice4"; value: 44 }

        onNameChanged:              console.log("pieSeries.onNameChanged: " + name);
        onVisibleChanged:           console.log("pieSeries.onVisibleChanged: " + series.visible);
        onOpacityChanged:           console.log("pieSeries.onOpacityChanged: " + opacity);
        onClicked:                  console.log("pieSeries.onClicked: " + slice.label);
        onHovered:                  console.log("pieSeries.onHovered: " + slice.label);
        onAdded:                    console.log("pieSeries.onAdded: " + slices);
        onSliceAdded:               console.log("pieSeries.onSliceAdded: " + slice.label);
        onRemoved:                  console.log("pieSeries.onRemoved: " + slices);
        onSliceRemoved:             console.log("pieSeries.onSliceRemoved: " + slice.label);
        onCountChanged:             console.log("pieSeries.onCountChanged: " + count);
        onSumChanged:               console.log("pieSeries.onSumChanged: " + sum);
    }
}
