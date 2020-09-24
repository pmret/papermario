.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_draw_menu_label
/* 1421D4 8024EE94 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1421D8 8024EE98 AFBF0028 */  sw        $ra, 0x28($sp)
/* 1421DC 8024EE9C 0080382D */  daddu     $a3, $a0, $zero
/* 1421E0 8024EEA0 00A0402D */  daddu     $t0, $a1, $zero
/* 1421E4 8024EEA4 00C0482D */  daddu     $t1, $a2, $zero
/* 1421E8 8024EEA8 24020008 */  addiu     $v0, $zero, 8
/* 1421EC 8024EEAC 14E20002 */  bne       $a3, $v0, .L8024EEB8
/* 1421F0 8024EEB0 24060040 */   addiu    $a2, $zero, 0x40
/* 1421F4 8024EEB4 24060080 */  addiu     $a2, $zero, 0x80
.L8024EEB8:
/* 1421F8 8024EEB8 24020003 */  addiu     $v0, $zero, 3
/* 1421FC 8024EEBC 50E20001 */  beql      $a3, $v0, .L8024EEC4
/* 142200 8024EEC0 24060030 */   addiu    $a2, $zero, 0x30
.L8024EEC4:
/* 142204 8024EEC4 24020004 */  addiu     $v0, $zero, 4
/* 142208 8024EEC8 50E20001 */  beql      $a3, $v0, .L8024EED0
/* 14220C 8024EECC 24060030 */   addiu    $a2, $zero, 0x30
.L8024EED0:
/* 142210 8024EED0 24020005 */  addiu     $v0, $zero, 5
/* 142214 8024EED4 50E20001 */  beql      $a3, $v0, .L8024EEDC
/* 142218 8024EED8 24060030 */   addiu    $a2, $zero, 0x30
.L8024EEDC:
/* 14221C 8024EEDC 24020006 */  addiu     $v0, $zero, 6
/* 142220 8024EEE0 50E20001 */  beql      $a3, $v0, .L8024EEE8
/* 142224 8024EEE4 240600A0 */   addiu    $a2, $zero, 0xa0
.L8024EEE8:
/* 142228 8024EEE8 3C05800A */  lui       $a1, 0x800a
/* 14222C 8024EEEC 24A5A66C */  addiu     $a1, $a1, -0x5994
/* 142230 8024EEF0 3C02DE00 */  lui       $v0, 0xde00
/* 142234 8024EEF4 01063021 */  addu      $a2, $t0, $a2
/* 142238 8024EEF8 8CA30000 */  lw        $v1, ($a1)
/* 14223C 8024EEFC 00063080 */  sll       $a2, $a2, 2
/* 142240 8024EF00 0060202D */  daddu     $a0, $v1, $zero
/* 142244 8024EF04 AC820000 */  sw        $v0, ($a0)
/* 142248 8024EF08 00071080 */  sll       $v0, $a3, 2
/* 14224C 8024EF0C 24630008 */  addiu     $v1, $v1, 8
/* 142250 8024EF10 3C018027 */  lui       $at, 0x8027
/* 142254 8024EF14 00220821 */  addu      $at, $at, $v0
/* 142258 8024EF18 8C22F8D4 */  lw        $v0, -0x72c($at)
/* 14225C 8024EF1C 25270010 */  addiu     $a3, $t1, 0x10
/* 142260 8024EF20 ACA30000 */  sw        $v1, ($a1)
/* 142264 8024EF24 00092880 */  sll       $a1, $t1, 2
/* 142268 8024EF28 00073880 */  sll       $a3, $a3, 2
/* 14226C 8024EF2C AC820004 */  sw        $v0, 4($a0)
/* 142270 8024EF30 24020400 */  addiu     $v0, $zero, 0x400
/* 142274 8024EF34 00082080 */  sll       $a0, $t0, 2
/* 142278 8024EF38 AFA00010 */  sw        $zero, 0x10($sp)
/* 14227C 8024EF3C AFA00014 */  sw        $zero, 0x14($sp)
/* 142280 8024EF40 AFA00018 */  sw        $zero, 0x18($sp)
/* 142284 8024EF44 AFA2001C */  sw        $v0, 0x1c($sp)
/* 142288 8024EF48 0C091216 */  jal       pause_draw_rect
/* 14228C 8024EF4C AFA20020 */   sw       $v0, 0x20($sp)
/* 142290 8024EF50 8FBF0028 */  lw        $ra, 0x28($sp)
/* 142294 8024EF54 03E00008 */  jr        $ra
/* 142298 8024EF58 27BD0030 */   addiu    $sp, $sp, 0x30
/* 14229C 8024EF5C 00000000 */  nop       
