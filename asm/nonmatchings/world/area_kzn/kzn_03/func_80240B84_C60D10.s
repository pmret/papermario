.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B84_C61894
/* C61894 80240B84 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C61898 80240B88 0080102D */  daddu     $v0, $a0, $zero
/* C6189C 80240B8C AFB00010 */  sw        $s0, 0x10($sp)
/* C618A0 80240B90 AFBF0018 */  sw        $ra, 0x18($sp)
/* C618A4 80240B94 AFB10014 */  sw        $s1, 0x14($sp)
/* C618A8 80240B98 8C44014C */  lw        $a0, 0x14c($v0)
/* C618AC 80240B9C 8C510148 */  lw        $s1, 0x148($v0)
/* C618B0 80240BA0 0C00EAD2 */  jal       get_npc_safe
/* C618B4 80240BA4 00A0802D */   daddu    $s0, $a1, $zero
/* C618B8 80240BA8 56000001 */  bnel      $s0, $zero, .L80240BB0
/* C618BC 80240BAC A04000AB */   sb       $zero, 0xab($v0)
.L80240BB0:
/* C618C0 80240BB0 8C420000 */  lw        $v0, ($v0)
/* C618C4 80240BB4 30421000 */  andi      $v0, $v0, 0x1000
/* C618C8 80240BB8 1040000A */  beqz      $v0, .L80240BE4
/* C618CC 80240BBC 0000102D */   daddu    $v0, $zero, $zero
/* C618D0 80240BC0 82220004 */  lb        $v0, 4($s1)
/* C618D4 80240BC4 3C03800B */  lui       $v1, %hi(gCurrentEncounter)
/* C618D8 80240BC8 24630F10 */  addiu     $v1, $v1, %lo(gCurrentEncounter)
/* C618DC 80240BCC 00021080 */  sll       $v0, $v0, 2
/* C618E0 80240BD0 00431021 */  addu      $v0, $v0, $v1
/* C618E4 80240BD4 8C440028 */  lw        $a0, 0x28($v0)
/* C618E8 80240BD8 9623006E */  lhu       $v1, 0x6e($s1)
/* C618EC 80240BDC 24020002 */  addiu     $v0, $zero, 2
/* C618F0 80240BE0 A4830044 */  sh        $v1, 0x44($a0)
.L80240BE4:
/* C618F4 80240BE4 8FBF0018 */  lw        $ra, 0x18($sp)
/* C618F8 80240BE8 8FB10014 */  lw        $s1, 0x14($sp)
/* C618FC 80240BEC 8FB00010 */  lw        $s0, 0x10($sp)
/* C61900 80240BF0 03E00008 */  jr        $ra
/* C61904 80240BF4 27BD0020 */   addiu    $sp, $sp, 0x20
