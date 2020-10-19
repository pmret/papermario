.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240400_BE3BB0
/* BE3BB0 80240400 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BE3BB4 80240404 AFB3001C */  sw        $s3, 0x1c($sp)
/* BE3BB8 80240408 0080982D */  daddu     $s3, $a0, $zero
/* BE3BBC 8024040C AFBF0020 */  sw        $ra, 0x20($sp)
/* BE3BC0 80240410 AFB20018 */  sw        $s2, 0x18($sp)
/* BE3BC4 80240414 AFB10014 */  sw        $s1, 0x14($sp)
/* BE3BC8 80240418 AFB00010 */  sw        $s0, 0x10($sp)
/* BE3BCC 8024041C 8E720148 */  lw        $s2, 0x148($s3)
/* BE3BD0 80240420 86440008 */  lh        $a0, 8($s2)
/* BE3BD4 80240424 0C00EABB */  jal       get_npc_unsafe
/* BE3BD8 80240428 00A0882D */   daddu    $s1, $a1, $zero
/* BE3BDC 8024042C 8E240008 */  lw        $a0, 8($s1)
/* BE3BE0 80240430 0040802D */  daddu     $s0, $v0, $zero
/* BE3BE4 80240434 00041FC2 */  srl       $v1, $a0, 0x1f
/* BE3BE8 80240438 00832021 */  addu      $a0, $a0, $v1
/* BE3BEC 8024043C 00042043 */  sra       $a0, $a0, 1
/* BE3BF0 80240440 0C00A67F */  jal       rand_int
/* BE3BF4 80240444 24840001 */   addiu    $a0, $a0, 1
/* BE3BF8 80240448 8E230008 */  lw        $v1, 8($s1)
/* BE3BFC 8024044C 240400B4 */  addiu     $a0, $zero, 0xb4
/* BE3C00 80240450 00032FC2 */  srl       $a1, $v1, 0x1f
/* BE3C04 80240454 00651821 */  addu      $v1, $v1, $a1
/* BE3C08 80240458 00031843 */  sra       $v1, $v1, 1
/* BE3C0C 8024045C 00621821 */  addu      $v1, $v1, $v0
/* BE3C10 80240460 0C00A67F */  jal       rand_int
/* BE3C14 80240464 A603008E */   sh       $v1, 0x8e($s0)
/* BE3C18 80240468 C60C000C */  lwc1      $f12, 0xc($s0)
/* BE3C1C 8024046C 44820000 */  mtc1      $v0, $f0
/* BE3C20 80240470 00000000 */  nop       
/* BE3C24 80240474 46800020 */  cvt.s.w   $f0, $f0
/* BE3C28 80240478 46006300 */  add.s     $f12, $f12, $f0
/* BE3C2C 8024047C 3C0142B4 */  lui       $at, 0x42b4
/* BE3C30 80240480 44810000 */  mtc1      $at, $f0
/* BE3C34 80240484 0C00A6C9 */  jal       clamp_angle
/* BE3C38 80240488 46006301 */   sub.s    $f12, $f12, $f0
/* BE3C3C 8024048C E600000C */  swc1      $f0, 0xc($s0)
/* BE3C40 80240490 8E4200CC */  lw        $v0, 0xcc($s2)
/* BE3C44 80240494 8C420000 */  lw        $v0, ($v0)
/* BE3C48 80240498 AE020028 */  sw        $v0, 0x28($s0)
/* BE3C4C 8024049C 24020003 */  addiu     $v0, $zero, 3
/* BE3C50 802404A0 AE620070 */  sw        $v0, 0x70($s3)
/* BE3C54 802404A4 8FBF0020 */  lw        $ra, 0x20($sp)
/* BE3C58 802404A8 8FB3001C */  lw        $s3, 0x1c($sp)
/* BE3C5C 802404AC 8FB20018 */  lw        $s2, 0x18($sp)
/* BE3C60 802404B0 8FB10014 */  lw        $s1, 0x14($sp)
/* BE3C64 802404B4 8FB00010 */  lw        $s0, 0x10($sp)
/* BE3C68 802404B8 03E00008 */  jr        $ra
/* BE3C6C 802404BC 27BD0028 */   addiu    $sp, $sp, 0x28
