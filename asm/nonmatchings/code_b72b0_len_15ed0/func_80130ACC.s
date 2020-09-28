.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80130ACC
/* C71CC 80130ACC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C71D0 80130AD0 AFB00010 */  sw        $s0, 0x10($sp)
/* C71D4 80130AD4 0080802D */  daddu     $s0, $a0, $zero
/* C71D8 80130AD8 AFBF0014 */  sw        $ra, 0x14($sp)
/* C71DC 80130ADC 8E02003C */  lw        $v0, 0x3c($s0)
/* C71E0 80130AE0 2442FFFF */  addiu     $v0, $v0, -1
/* C71E4 80130AE4 1C400005 */  bgtz      $v0, .L80130AFC
/* C71E8 80130AE8 AE02003C */   sw       $v0, 0x3c($s0)
.L80130AEC:
/* C71EC 80130AEC 0C04C281 */  jal       func_80130A04
/* C71F0 80130AF0 0200202D */   daddu    $a0, $s0, $zero
/* C71F4 80130AF4 1440FFFD */  bnez      $v0, .L80130AEC
/* C71F8 80130AF8 00000000 */   nop      
.L80130AFC:
/* C71FC 80130AFC 8FBF0014 */  lw        $ra, 0x14($sp)
/* C7200 80130B00 8FB00010 */  lw        $s0, 0x10($sp)
/* C7204 80130B04 03E00008 */  jr        $ra
/* C7208 80130B08 27BD0018 */   addiu    $sp, $sp, 0x18
