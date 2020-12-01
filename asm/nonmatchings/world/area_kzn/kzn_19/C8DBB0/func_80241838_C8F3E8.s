.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241838_C8F3E8
/* C8F3E8 80241838 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8F3EC 8024183C AFBF0010 */  sw        $ra, 0x10($sp)
/* C8F3F0 80241840 8C82000C */  lw        $v0, 0xc($a0)
/* C8F3F4 80241844 0C0B1EAF */  jal       get_variable
/* C8F3F8 80241848 8C450000 */   lw       $a1, ($v0)
/* C8F3FC 8024184C 0040182D */  daddu     $v1, $v0, $zero
/* C8F400 80241850 10600012 */  beqz      $v1, .L8024189C
/* C8F404 80241854 0000202D */   daddu    $a0, $zero, $zero
/* C8F408 80241858 8C620000 */  lw        $v0, ($v1)
/* C8F40C 8024185C 5040000A */  beql      $v0, $zero, .L80241888
/* C8F410 80241860 00041080 */   sll      $v0, $a0, 2
/* C8F414 80241864 3C058025 */  lui       $a1, %hi(D_80248388)
/* C8F418 80241868 24A58388 */  addiu     $a1, $a1, %lo(D_80248388)
.L8024186C:
/* C8F41C 8024186C 24630004 */  addiu     $v1, $v1, 4
/* C8F420 80241870 24840001 */  addiu     $a0, $a0, 1
/* C8F424 80241874 ACA20000 */  sw        $v0, ($a1)
/* C8F428 80241878 8C620000 */  lw        $v0, ($v1)
/* C8F42C 8024187C 1440FFFB */  bnez      $v0, .L8024186C
/* C8F430 80241880 24A50004 */   addiu    $a1, $a1, 4
/* C8F434 80241884 00041080 */  sll       $v0, $a0, 2
.L80241888:
/* C8F438 80241888 3C018025 */  lui       $at, %hi(D_80248388)
/* C8F43C 8024188C 00220821 */  addu      $at, $at, $v0
/* C8F440 80241890 AC208388 */  sw        $zero, %lo(D_80248388)($at)
/* C8F444 80241894 08090631 */  j         .L802418C4
/* C8F448 80241898 00000000 */   nop      
.L8024189C:
/* C8F44C 8024189C 3C038025 */  lui       $v1, %hi(D_80248388)
/* C8F450 802418A0 24638388 */  addiu     $v1, $v1, %lo(D_80248388)
/* C8F454 802418A4 0060282D */  daddu     $a1, $v1, $zero
.L802418A8:
/* C8F458 802418A8 24820010 */  addiu     $v0, $a0, 0x10
/* C8F45C 802418AC AC620000 */  sw        $v0, ($v1)
/* C8F460 802418B0 24630004 */  addiu     $v1, $v1, 4
/* C8F464 802418B4 24840001 */  addiu     $a0, $a0, 1
/* C8F468 802418B8 28820070 */  slti      $v0, $a0, 0x70
/* C8F46C 802418BC 1440FFFA */  bnez      $v0, .L802418A8
/* C8F470 802418C0 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802418C4:
/* C8F474 802418C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C8F478 802418C8 24020002 */  addiu     $v0, $zero, 2
/* C8F47C 802418CC 03E00008 */  jr        $ra
/* C8F480 802418D0 27BD0018 */   addiu    $sp, $sp, 0x18
