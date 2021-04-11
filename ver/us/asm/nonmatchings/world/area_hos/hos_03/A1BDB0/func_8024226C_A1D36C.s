.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hos_03_UnkFunc33
/* A1D36C 8024226C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1D370 80242270 AFB10014 */  sw        $s1, 0x14($sp)
/* A1D374 80242274 0080882D */  daddu     $s1, $a0, $zero
/* A1D378 80242278 AFBF0018 */  sw        $ra, 0x18($sp)
/* A1D37C 8024227C AFB00010 */  sw        $s0, 0x10($sp)
/* A1D380 80242280 8E30000C */  lw        $s0, 0xc($s1)
/* A1D384 80242284 8E050000 */  lw        $a1, ($s0)
/* A1D388 80242288 0C0B1EAF */  jal       get_variable
/* A1D38C 8024228C 26100004 */   addiu    $s0, $s0, 4
/* A1D390 80242290 0220202D */  daddu     $a0, $s1, $zero
/* A1D394 80242294 8E050000 */  lw        $a1, ($s0)
/* A1D398 80242298 0C0B1EAF */  jal       get_variable
/* A1D39C 8024229C 0040802D */   daddu    $s0, $v0, $zero
/* A1D3A0 802422A0 44820000 */  mtc1      $v0, $f0
/* A1D3A4 802422A4 00000000 */  nop
/* A1D3A8 802422A8 46800020 */  cvt.s.w   $f0, $f0
/* A1D3AC 802422AC 24020002 */  addiu     $v0, $zero, 2
/* A1D3B0 802422B0 00501804 */  sllv      $v1, $s0, $v0
/* A1D3B4 802422B4 00701821 */  addu      $v1, $v1, $s0
/* A1D3B8 802422B8 00431804 */  sllv      $v1, $v1, $v0
/* A1D3BC 802422BC 00701823 */  subu      $v1, $v1, $s0
/* A1D3C0 802422C0 000320C0 */  sll       $a0, $v1, 3
/* A1D3C4 802422C4 00641821 */  addu      $v1, $v1, $a0
/* A1D3C8 802422C8 000318C0 */  sll       $v1, $v1, 3
/* A1D3CC 802422CC 3C01800B */  lui       $at, %hi(gCameras+0x18)
/* A1D3D0 802422D0 00230821 */  addu      $at, $at, $v1
/* A1D3D4 802422D4 E4201D98 */  swc1      $f0, %lo(gCameras+0x18)($at)
/* A1D3D8 802422D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* A1D3DC 802422DC 8FB10014 */  lw        $s1, 0x14($sp)
/* A1D3E0 802422E0 8FB00010 */  lw        $s0, 0x10($sp)
/* A1D3E4 802422E4 03E00008 */  jr        $ra
/* A1D3E8 802422E8 27BD0020 */   addiu    $sp, $sp, 0x20
