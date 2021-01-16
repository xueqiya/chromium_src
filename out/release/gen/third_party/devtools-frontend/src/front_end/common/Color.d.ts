/**
 * @unrestricted
 */
export class Color {
    /**
     * @param {!Array.<number>} rgba
     * @param {!Format} format
     * @param {string=} originalText
     */
    constructor(rgba: number[], format: string, originalText?: string | undefined);
    _hsla: number[] | undefined;
    _rgba: number[];
    _originalText: string | null;
    _originalTextIsValid: boolean;
    _format: string;
    /**
     * @return {!Format}
     */
    format(): string;
    /**
     * @return {!Array.<number>} HSLA with components within [0..1]
     */
    hsla(): number[];
    /**
     * @return {!Array.<number>}
     */
    canonicalHSLA(): number[];
    /**
     * @return {!Array.<number>} HSVA with components within [0..1]
     */
    hsva(): number[];
    /**
     * @return {boolean}
     */
    hasAlpha(): boolean;
    /**
     * @return {!Format}
     */
    detectHEXFormat(): string;
    /**
     * @param {?string} format
     * @return {?string}
     */
    asString(format: string | null): string | null;
    /**
     * @return {!Array<number>}
     */
    rgba(): number[];
    /**
     * @return {!Array.<number>}
     */
    canonicalRGBA(): number[];
    /**
     * @return {?string} nickname
     */
    nickname(): string | null;
    /**
     * @return {!{r: number, g: number, b: number, a: (number|undefined)}}
     */
    toProtocolRGBA(): {
        r: number;
        g: number;
        b: number;
        a: number | undefined;
    };
    /**
     * @return {!Color}
     */
    invert(): Color;
    /**
     * @param {number} alpha
     * @return {!Color}
     */
    setAlpha(alpha: number): Color;
    /**
     * @param {!Color} fgColor
     * @return {!Color}
     */
    blendWith(fgColor: Color): Color;
}
export namespace Color {
    export namespace hsva2rgba {
        export const _tmpHSLA: Array<number>;
    }
    export namespace calculateContrastRatio {
        export const _blendedFg: number[];
    }
}
/** @type {!RegExp} */
export const Regex: RegExp;
export type Format = string;
export namespace Format {
    export const Original: string;
    export const Nickname: string;
    export const HEX: string;
    export const ShortHEX: string;
    export const HEXA: string;
    export const ShortHEXA: string;
    export const RGB: string;
    export const RGBA: string;
    export const HSL: string;
    export const HSLA: string;
}
/** @type {!Object<string, !Array.<number>>} */
export const Nicknames: {
    [x: string]: Array<number>;
};
export namespace PageHighlight {
    export const Content: Color;
    export const ContentLight: Color;
    export const ContentOutline: Color;
    export const Padding: Color;
    export const PaddingLight: Color;
    export const Border: Color;
    export const BorderLight: Color;
    export const Margin: Color;
    export const MarginLight: Color;
    export const EventTarget: Color;
    export const Shape: Color;
    export const ShapeMargin: Color;
    export const CssGrid: Color;
}
export class Generator {
    /**
     * @param {!{min: number, max: number, count: (number|undefined)}|number=} hueSpace
     * @param {!{min: number, max: number, count: (number|undefined)}|number=} satSpace
     * @param {!{min: number, max: number, count: (number|undefined)}|number=} lightnessSpace
     * @param {!{min: number, max: number, count: (number|undefined)}|number=} alphaSpace
     */
    constructor(hueSpace?: number | {
        min: number;
        max: number;
        count: number | undefined;
    } | undefined, satSpace?: number | {
        min: number;
        max: number;
        count: number | undefined;
    } | undefined, lightnessSpace?: number | {
        min: number;
        max: number;
        count: number | undefined;
    } | undefined, alphaSpace?: number | {
        min: number;
        max: number;
        count: number | undefined;
    } | undefined);
    _hueSpace: number | {
        min: number;
        max: number;
        count: number | undefined;
    };
    _satSpace: number | {
        min: number;
        max: number;
        count: number | undefined;
    };
    _lightnessSpace: number | {
        min: number;
        max: number;
        count: number | undefined;
    };
    _alphaSpace: number | {
        min: number;
        max: number;
        count: number | undefined;
    };
    /** @type {!Map<string, string>} */
    _colors: Map<string, string>;
    /**
     * @param {string} id
     * @param {string} color
     */
    setColorForID(id: string, color: string): void;
    /**
     * @param {string} id
     * @return {string}
     */
    colorForID(id: string): string;
    /**
     * @param {string} id
     * @return {string}
     */
    _generateColorForID(id: string): string;
    /**
     * @param {number} index
     * @param {!{min: number, max: number, count: (number|undefined)}|number} space
     * @return {number}
     */
    _indexToValueInSpace(index: number, space: number | {
        min: number;
        max: number;
        count: number | undefined;
    }): number;
}
