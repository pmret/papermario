.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007C130
/* 37D5C0 E007C130 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 37D5C4 E007C134 AFBF0010 */  sw        $ra, 0x10($sp)
/* 37D5C8 E007C138 8C85000C */  lw        $a1, 0xc($a0)
/* 37D5CC E007C13C 3C014110 */  lui       $at, 0x4110
/* 37D5D0 E007C140 44810000 */  mtc1      $at, $f0
/* 37D5D4 E007C144 8CA20018 */  lw        $v0, 0x18($a1)
/* 37D5D8 E007C148 8CA30014 */  lw        $v1, 0x14($a1)
/* 37D5DC E007C14C 44821000 */  mtc1      $v0, $f2
/* 37D5E0 E007C150 00000000 */  nop
/* 37D5E4 E007C154 468010A0 */  cvt.s.w   $f2, $f2
/* 37D5E8 E007C158 24420001 */  addiu     $v0, $v0, 1
/* 37D5EC E007C15C 46001082 */  mul.s     $f2, $f2, $f0
/* 37D5F0 E007C160 00000000 */  nop
/* 37D5F4 E007C164 2463FFFF */  addiu     $v1, $v1, -1
/* 37D5F8 E007C168 C4A0001C */  lwc1      $f0, 0x1c($a1)
/* 37D5FC E007C16C 46800020 */  cvt.s.w   $f0, $f0
/* 37D600 E007C170 ACA20018 */  sw        $v0, 0x18($a1)
/* 37D604 E007C174 ACA30014 */  sw        $v1, 0x14($a1)
/* 37D608 E007C178 46001083 */  div.s     $f2, $f2, $f0
/* 37D60C E007C17C 04610005 */  bgez      $v1, .LE007C194
/* 37D610 E007C180 E4A20020 */   swc1     $f2, 0x20($a1)
/* 37D614 E007C184 0C080128 */  jal       func_E02004A0
/* 37D618 E007C188 00000000 */   nop
/* 37D61C E007C18C 0801F069 */  j         .LE007C1A4
/* 37D620 E007C190 00000000 */   nop
.LE007C194:
/* 37D624 E007C194 C4A00024 */  lwc1      $f0, 0x24($a1)
/* 37D628 E007C198 C4A20028 */  lwc1      $f2, 0x28($a1)
/* 37D62C E007C19C 46020000 */  add.s     $f0, $f0, $f2
/* 37D630 E007C1A0 E4A00024 */  swc1      $f0, 0x24($a1)
.LE007C1A4:
/* 37D634 E007C1A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 37D638 E007C1A8 03E00008 */  jr        $ra
/* 37D63C E007C1AC 27BD0018 */   addiu    $sp, $sp, 0x18
