.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001C128
/* 330A38 E001C128 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 330A3C E001C12C AFBF0010 */  sw        $ra, 0x10($sp)
/* 330A40 E001C130 8C83000C */  lw        $v1, 0xc($a0)
/* 330A44 E001C134 8C620028 */  lw        $v0, 0x28($v1)
/* 330A48 E001C138 2442FFFF */  addiu     $v0, $v0, -1
/* 330A4C E001C13C 04410005 */  bgez      $v0, .LE001C154
/* 330A50 E001C140 AC620028 */   sw       $v0, 0x28($v1)
/* 330A54 E001C144 0C080128 */  jal       func_E02004A0
/* 330A58 E001C148 00000000 */   nop      
/* 330A5C E001C14C 0800707D */  j         .LE001C1F4
/* 330A60 E001C150 00000000 */   nop      
.LE001C154:
/* 330A64 E001C154 C4680000 */  lwc1      $f8, ($v1)
/* 330A68 E001C158 C460000C */  lwc1      $f0, 0xc($v1)
/* 330A6C E001C15C C4660004 */  lwc1      $f6, 4($v1)
/* 330A70 E001C160 46004200 */  add.s     $f8, $f8, $f0
/* 330A74 E001C164 C4600010 */  lwc1      $f0, 0x10($v1)
/* 330A78 E001C168 C4640018 */  lwc1      $f4, 0x18($v1)
/* 330A7C E001C16C 46003180 */  add.s     $f6, $f6, $f0
/* 330A80 E001C170 C4600020 */  lwc1      $f0, 0x20($v1)
/* 330A84 E001C174 C4620014 */  lwc1      $f2, 0x14($v1)
/* 330A88 E001C178 46002100 */  add.s     $f4, $f4, $f0
/* 330A8C E001C17C C4600008 */  lwc1      $f0, 8($v1)
/* 330A90 E001C180 3C014120 */  lui       $at, 0x4120
/* 330A94 E001C184 44815000 */  mtc1      $at, $f10
/* 330A98 E001C188 46020000 */  add.s     $f0, $f0, $f2
/* 330A9C E001C18C E4680000 */  swc1      $f8, ($v1)
/* 330AA0 E001C190 E4660004 */  swc1      $f6, 4($v1)
/* 330AA4 E001C194 460A203C */  c.lt.s    $f4, $f10
/* 330AA8 E001C198 E4640018 */  swc1      $f4, 0x18($v1)
/* 330AAC E001C19C 45000005 */  bc1f      .LE001C1B4
/* 330AB0 E001C1A0 E4600008 */   swc1     $f0, 8($v1)
/* 330AB4 E001C1A4 C4600020 */  lwc1      $f0, 0x20($v1)
/* 330AB8 E001C1A8 E46A0018 */  swc1      $f10, 0x18($v1)
/* 330ABC E001C1AC 46000007 */  neg.s     $f0, $f0
/* 330AC0 E001C1B0 E4600020 */  swc1      $f0, 0x20($v1)
.LE001C1B4:
/* 330AC4 E001C1B4 C4600018 */  lwc1      $f0, 0x18($v1)
/* 330AC8 E001C1B8 3C014234 */  lui       $at, 0x4234
/* 330ACC E001C1BC 44811000 */  mtc1      $at, $f2
/* 330AD0 E001C1C0 00000000 */  nop       
/* 330AD4 E001C1C4 4600103C */  c.lt.s    $f2, $f0
/* 330AD8 E001C1C8 00000000 */  nop       
/* 330ADC E001C1CC 45000005 */  bc1f      .LE001C1E4
/* 330AE0 E001C1D0 00000000 */   nop      
/* 330AE4 E001C1D4 C4600020 */  lwc1      $f0, 0x20($v1)
/* 330AE8 E001C1D8 E4620018 */  swc1      $f2, 0x18($v1)
/* 330AEC E001C1DC 46000007 */  neg.s     $f0, $f0
/* 330AF0 E001C1E0 E4600020 */  swc1      $f0, 0x20($v1)
.LE001C1E4:
/* 330AF4 E001C1E4 C460001C */  lwc1      $f0, 0x1c($v1)
/* 330AF8 E001C1E8 C4620024 */  lwc1      $f2, 0x24($v1)
/* 330AFC E001C1EC 46020000 */  add.s     $f0, $f0, $f2
/* 330B00 E001C1F0 E460001C */  swc1      $f0, 0x1c($v1)
.LE001C1F4:
/* 330B04 E001C1F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 330B08 E001C1F8 03E00008 */  jr        $ra
/* 330B0C E001C1FC 27BD0018 */   addiu    $sp, $sp, 0x18
