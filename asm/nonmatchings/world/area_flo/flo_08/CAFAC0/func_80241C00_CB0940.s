.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C00_CB0940
/* CB0940 80241C00 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* CB0944 80241C04 F7B40018 */  sdc1      $f20, 0x18($sp)
/* CB0948 80241C08 4485A000 */  mtc1      $a1, $f20
/* CB094C 80241C0C F7B60020 */  sdc1      $f22, 0x20($sp)
/* CB0950 80241C10 4486B000 */  mtc1      $a2, $f22
/* CB0954 80241C14 AFB00010 */  sw        $s0, 0x10($sp)
/* CB0958 80241C18 F7B80028 */  sdc1      $f24, 0x28($sp)
/* CB095C 80241C1C 4487C000 */  mtc1      $a3, $f24
/* CB0960 80241C20 AFBF0014 */  sw        $ra, 0x14($sp)
/* CB0964 80241C24 0C019D28 */  jal       guMtxIdentF
/* CB0968 80241C28 0080802D */   daddu    $s0, $a0, $zero
/* CB096C 80241C2C 4616A582 */  mul.s     $f22, $f20, $f22
/* CB0970 80241C30 00000000 */  nop       
/* CB0974 80241C34 4618A502 */  mul.s     $f20, $f20, $f24
/* CB0978 80241C38 00000000 */  nop       
/* CB097C 80241C3C 3C013F80 */  lui       $at, 0x3f80
/* CB0980 80241C40 44810000 */  mtc1      $at, $f0
/* CB0984 80241C44 00000000 */  nop       
/* CB0988 80241C48 E6000014 */  swc1      $f0, 0x14($s0)
/* CB098C 80241C4C E6160010 */  swc1      $f22, 0x10($s0)
/* CB0990 80241C50 E6140018 */  swc1      $f20, 0x18($s0)
/* CB0994 80241C54 8FBF0014 */  lw        $ra, 0x14($sp)
/* CB0998 80241C58 8FB00010 */  lw        $s0, 0x10($sp)
/* CB099C 80241C5C D7B80028 */  ldc1      $f24, 0x28($sp)
/* CB09A0 80241C60 D7B60020 */  ldc1      $f22, 0x20($sp)
/* CB09A4 80241C64 D7B40018 */  ldc1      $f20, 0x18($sp)
/* CB09A8 80241C68 03E00008 */  jr        $ra
/* CB09AC 80241C6C 27BD0030 */   addiu    $sp, $sp, 0x30
