.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C40_A0C930
/* A0C930 80240C40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A0C934 80240C44 240201F4 */  addiu     $v0, $zero, 0x1f4
/* A0C938 80240C48 0000202D */  daddu     $a0, $zero, $zero
/* A0C93C 80240C4C 0000282D */  daddu     $a1, $zero, $zero
/* A0C940 80240C50 3C018011 */  lui       $at, %hi(gPlayerStatus+0x28)
/* A0C944 80240C54 C420EFF0 */  lwc1      $f0, %lo(gPlayerStatus+0x28)($at)
/* A0C948 80240C58 3C014348 */  lui       $at, 0x4348
/* A0C94C 80240C5C 44811000 */  mtc1      $at, $f2
/* A0C950 80240C60 3C064358 */  lui       $a2, 0x4358
/* A0C954 80240C64 46020001 */  sub.s     $f0, $f0, $f2
/* A0C958 80240C68 AFBF0018 */  sw        $ra, 0x18($sp)
/* A0C95C 80240C6C 4600010D */  trunc.w.s $f4, $f0
/* A0C960 80240C70 44072000 */  mfc1      $a3, $f4
/* A0C964 80240C74 0C00A8ED */  jal       update_lerp
/* A0C968 80240C78 AFA20010 */   sw       $v0, 0x10($sp)
/* A0C96C 80240C7C 4600010D */  trunc.w.s $f4, $f0
/* A0C970 80240C80 44082000 */  mfc1      $t0, $f4
/* A0C974 80240C84 00000000 */  nop       
/* A0C978 80240C88 05020001 */  bltzl     $t0, .L80240C90
/* A0C97C 80240C8C 0000402D */   daddu    $t0, $zero, $zero
.L80240C90:
/* A0C980 80240C90 290200D9 */  slti      $v0, $t0, 0xd9
/* A0C984 80240C94 50400001 */  beql      $v0, $zero, .L80240C9C
/* A0C988 80240C98 240800D8 */   addiu    $t0, $zero, 0xd8
.L80240C9C:
/* A0C98C 80240C9C 3C05E300 */  lui       $a1, 0xe300
/* A0C990 80240CA0 34A50A01 */  ori       $a1, $a1, 0xa01
/* A0C994 80240CA4 3C07FCFF */  lui       $a3, 0xfcff
/* A0C998 80240CA8 34E7C7FF */  ori       $a3, $a3, 0xc7ff
/* A0C99C 80240CAC 3C06FF8E */  lui       $a2, 0xff8e
/* A0C9A0 80240CB0 3C04800A */  lui       $a0, 0x800a
/* A0C9A4 80240CB4 2484A66C */  addiu     $a0, $a0, -0x5994
/* A0C9A8 80240CB8 8C820000 */  lw        $v0, ($a0)
/* A0C9AC 80240CBC 34C67F3F */  ori       $a2, $a2, 0x7f3f
/* A0C9B0 80240CC0 0040182D */  daddu     $v1, $v0, $zero
/* A0C9B4 80240CC4 24420008 */  addiu     $v0, $v0, 8
/* A0C9B8 80240CC8 AC820000 */  sw        $v0, ($a0)
/* A0C9BC 80240CCC AC650000 */  sw        $a1, ($v1)
/* A0C9C0 80240CD0 AC600004 */  sw        $zero, 4($v1)
/* A0C9C4 80240CD4 24430008 */  addiu     $v1, $v0, 8
/* A0C9C8 80240CD8 AC830000 */  sw        $v1, ($a0)
/* A0C9CC 80240CDC 24430010 */  addiu     $v1, $v0, 0x10
/* A0C9D0 80240CE0 AC470000 */  sw        $a3, ($v0)
/* A0C9D4 80240CE4 AC460004 */  sw        $a2, 4($v0)
/* A0C9D8 80240CE8 AC830000 */  sw        $v1, ($a0)
/* A0C9DC 80240CEC 3C03FA00 */  lui       $v1, 0xfa00
/* A0C9E0 80240CF0 AC430008 */  sw        $v1, 8($v0)
/* A0C9E4 80240CF4 310300FF */  andi      $v1, $t0, 0xff
/* A0C9E8 80240CF8 AC43000C */  sw        $v1, 0xc($v0)
/* A0C9EC 80240CFC 8FBF0018 */  lw        $ra, 0x18($sp)
/* A0C9F0 80240D00 03E00008 */  jr        $ra
/* A0C9F4 80240D04 27BD0020 */   addiu    $sp, $sp, 0x20
/* A0C9F8 80240D08 00000000 */  nop       
/* A0C9FC 80240D0C 00000000 */  nop       
