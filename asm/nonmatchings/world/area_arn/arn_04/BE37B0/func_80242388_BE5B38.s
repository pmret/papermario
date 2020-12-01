.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242388_BE5B38
/* BE5B38 80242388 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* BE5B3C 8024238C AFBF001C */  sw        $ra, 0x1c($sp)
/* BE5B40 80242390 AFB20018 */  sw        $s2, 0x18($sp)
/* BE5B44 80242394 AFB10014 */  sw        $s1, 0x14($sp)
/* BE5B48 80242398 AFB00010 */  sw        $s0, 0x10($sp)
/* BE5B4C 8024239C F7B40020 */  sdc1      $f20, 0x20($sp)
/* BE5B50 802423A0 8C900148 */  lw        $s0, 0x148($a0)
/* BE5B54 802423A4 86040008 */  lh        $a0, 8($s0)
/* BE5B58 802423A8 3C014387 */  lui       $at, 0x4387
/* BE5B5C 802423AC 4481A000 */  mtc1      $at, $f20
/* BE5B60 802423B0 0C00EABB */  jal       get_npc_unsafe
/* BE5B64 802423B4 00A0882D */   daddu    $s1, $a1, $zero
/* BE5B68 802423B8 0200202D */  daddu     $a0, $s0, $zero
/* BE5B6C 802423BC 8E26000C */  lw        $a2, 0xc($s1)
/* BE5B70 802423C0 8E270010 */  lw        $a3, 0x10($s1)
/* BE5B74 802423C4 0040882D */  daddu     $s1, $v0, $zero
/* BE5B78 802423C8 3C03800B */  lui       $v1, %hi(gCameras)
/* BE5B7C 802423CC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* BE5B80 802423D0 3C02800A */  lui       $v0, %hi(D_8009A634)
/* BE5B84 802423D4 8442A634 */  lh        $v0, %lo(D_8009A634)($v0)
/* BE5B88 802423D8 0000282D */  daddu     $a1, $zero, $zero
/* BE5B8C 802423DC 00028080 */  sll       $s0, $v0, 2
/* BE5B90 802423E0 02028021 */  addu      $s0, $s0, $v0
/* BE5B94 802423E4 00108080 */  sll       $s0, $s0, 2
/* BE5B98 802423E8 02028023 */  subu      $s0, $s0, $v0
/* BE5B9C 802423EC 001010C0 */  sll       $v0, $s0, 3
/* BE5BA0 802423F0 02028021 */  addu      $s0, $s0, $v0
/* BE5BA4 802423F4 001080C0 */  sll       $s0, $s0, 3
/* BE5BA8 802423F8 0C0124FB */  jal       func_800493EC
/* BE5BAC 802423FC 02038021 */   addu     $s0, $s0, $v1
/* BE5BB0 80242400 C60C006C */  lwc1      $f12, 0x6c($s0)
/* BE5BB4 80242404 C62E000C */  lwc1      $f14, 0xc($s1)
/* BE5BB8 80242408 0C00A70A */  jal       get_clamped_angle_diff
/* BE5BBC 8024240C 0002802B */   sltu     $s0, $zero, $v0
/* BE5BC0 80242410 0C00A6C9 */  jal       clamp_angle
/* BE5BC4 80242414 46000306 */   mov.s    $f12, $f0
/* BE5BC8 80242418 3C018024 */  lui       $at, %hi(D_80244328)
/* BE5BCC 8024241C D4224328 */  ldc1      $f2, %lo(D_80244328)($at)
/* BE5BD0 80242420 46000021 */  cvt.d.s   $f0, $f0
/* BE5BD4 80242424 4622003C */  c.lt.d    $f0, $f2
/* BE5BD8 80242428 00000000 */  nop       
/* BE5BDC 8024242C 45000003 */  bc1f      .L8024243C
/* BE5BE0 80242430 00000000 */   nop      
/* BE5BE4 80242434 3C0142B4 */  lui       $at, 0x42b4
/* BE5BE8 80242438 4481A000 */  mtc1      $at, $f20
.L8024243C:
/* BE5BEC 8024243C 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* BE5BF0 80242440 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* BE5BF4 80242444 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BE5BF8 80242448 8E420000 */  lw        $v0, ($s2)
/* BE5BFC 8024244C C62E0040 */  lwc1      $f14, 0x40($s1)
/* BE5C00 80242450 8C460028 */  lw        $a2, 0x28($v0)
/* BE5C04 80242454 0C00A720 */  jal       atan2
/* BE5C08 80242458 8C470030 */   lw       $a3, 0x30($v0)
/* BE5C0C 8024245C 4600A306 */  mov.s     $f12, $f20
/* BE5C10 80242460 0C00A70A */  jal       get_clamped_angle_diff
/* BE5C14 80242464 46000386 */   mov.s    $f14, $f0
/* BE5C18 80242468 46000005 */  abs.s     $f0, $f0
/* BE5C1C 8024246C 3C018024 */  lui       $at, %hi(D_80244330)
/* BE5C20 80242470 D4224330 */  ldc1      $f2, %lo(D_80244330)($at)
/* BE5C24 80242474 46000021 */  cvt.d.s   $f0, $f0
/* BE5C28 80242478 4620103C */  c.lt.d    $f2, $f0
/* BE5C2C 8024247C 00000000 */  nop       
/* BE5C30 80242480 45030001 */  bc1tl     .L80242488
/* BE5C34 80242484 0000802D */   daddu    $s0, $zero, $zero
.L80242488:
/* BE5C38 80242488 8E420000 */  lw        $v0, ($s2)
/* BE5C3C 8024248C C620003C */  lwc1      $f0, 0x3c($s1)
/* BE5C40 80242490 C442002C */  lwc1      $f2, 0x2c($v0)
/* BE5C44 80242494 46020001 */  sub.s     $f0, $f0, $f2
/* BE5C48 80242498 3C014220 */  lui       $at, 0x4220
/* BE5C4C 8024249C 44811000 */  mtc1      $at, $f2
/* BE5C50 802424A0 46000005 */  abs.s     $f0, $f0
/* BE5C54 802424A4 4600103E */  c.le.s    $f2, $f0
/* BE5C58 802424A8 00000000 */  nop       
/* BE5C5C 802424AC 45030001 */  bc1tl     .L802424B4
/* BE5C60 802424B0 0000802D */   daddu    $s0, $zero, $zero
.L802424B4:
/* BE5C64 802424B4 3C038011 */  lui       $v1, %hi(D_8010EBB3)
/* BE5C68 802424B8 8063EBB3 */  lb        $v1, %lo(D_8010EBB3)($v1)
/* BE5C6C 802424BC 24020009 */  addiu     $v0, $zero, 9
/* BE5C70 802424C0 50620001 */  beql      $v1, $v0, .L802424C8
/* BE5C74 802424C4 0000802D */   daddu    $s0, $zero, $zero
.L802424C8:
/* BE5C78 802424C8 0200102D */  daddu     $v0, $s0, $zero
/* BE5C7C 802424CC 8FBF001C */  lw        $ra, 0x1c($sp)
/* BE5C80 802424D0 8FB20018 */  lw        $s2, 0x18($sp)
/* BE5C84 802424D4 8FB10014 */  lw        $s1, 0x14($sp)
/* BE5C88 802424D8 8FB00010 */  lw        $s0, 0x10($sp)
/* BE5C8C 802424DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* BE5C90 802424E0 03E00008 */  jr        $ra
/* BE5C94 802424E4 27BD0028 */   addiu    $sp, $sp, 0x28
