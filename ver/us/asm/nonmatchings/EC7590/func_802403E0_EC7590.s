.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403E0_EC7590
/* EC7590 802403E0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EC7594 802403E4 F7B40018 */  sdc1      $f20, 0x18($sp)
/* EC7598 802403E8 4485A000 */  mtc1      $a1, $f20
/* EC759C 802403EC F7B60020 */  sdc1      $f22, 0x20($sp)
/* EC75A0 802403F0 4486B000 */  mtc1      $a2, $f22
/* EC75A4 802403F4 AFB00010 */  sw        $s0, 0x10($sp)
/* EC75A8 802403F8 F7B80028 */  sdc1      $f24, 0x28($sp)
/* EC75AC 802403FC 4487C000 */  mtc1      $a3, $f24
/* EC75B0 80240400 AFBF0014 */  sw        $ra, 0x14($sp)
/* EC75B4 80240404 0C01B198 */  jal       osGetCause
/* EC75B8 80240408 0080802D */   daddu    $s0, $a0, $zero
/* EC75BC 8024040C 4616A582 */  mul.s     $f22, $f20, $f22
/* EC75C0 80240410 00000000 */  nop
/* EC75C4 80240414 4618A502 */  mul.s     $f20, $f20, $f24
/* EC75C8 80240418 00000000 */  nop
/* EC75CC 8024041C 3C013F80 */  lui       $at, 0x3f80
/* EC75D0 80240420 44810000 */  mtc1      $at, $f0
/* EC75D4 80240424 00000000 */  nop
/* EC75D8 80240428 E6000014 */  swc1      $f0, 0x14($s0)
/* EC75DC 8024042C E6160010 */  swc1      $f22, 0x10($s0)
/* EC75E0 80240430 E6140018 */  swc1      $f20, 0x18($s0)
/* EC75E4 80240434 8FBF0014 */  lw        $ra, 0x14($sp)
/* EC75E8 80240438 8FB00010 */  lw        $s0, 0x10($sp)
/* EC75EC 8024043C D7B80028 */  ldc1      $f24, 0x28($sp)
/* EC75F0 80240440 D7B60020 */  ldc1      $f22, 0x20($sp)
/* EC75F4 80240444 D7B40018 */  ldc1      $f20, 0x18($sp)
/* EC75F8 80240448 03E00008 */  jr        $ra
/* EC75FC 8024044C 27BD0030 */   addiu    $sp, $sp, 0x30
