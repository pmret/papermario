.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406D0_EC7880
/* EC7880 802406D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EC7884 802406D4 AFB00010 */  sw        $s0, 0x10($sp)
/* EC7888 802406D8 0080802D */  daddu     $s0, $a0, $zero
/* EC788C 802406DC AFBF0018 */  sw        $ra, 0x18($sp)
/* EC7890 802406E0 AFB10014 */  sw        $s1, 0x14($sp)
/* EC7894 802406E4 8E02000C */  lw        $v0, 0xc($s0)
/* EC7898 802406E8 8C510000 */  lw        $s1, ($v0)
/* EC789C 802406EC 0C0B53A3 */  jal       func_802D4E8C
/* EC78A0 802406F0 0220282D */   daddu    $a1, $s1, $zero
/* EC78A4 802406F4 3C03FFF0 */  lui       $v1, 0xfff0
/* EC78A8 802406F8 3463FFFF */  ori       $v1, $v1, 0xffff
/* EC78AC 802406FC 0200202D */  daddu     $a0, $s0, $zero
/* EC78B0 80240700 00431024 */  and       $v0, $v0, $v1
/* EC78B4 80240704 00021140 */  sll       $v0, $v0, 5
/* EC78B8 80240708 3C068009 */  lui       $a2, %hi(D_8008D2C0)
/* EC78BC 8024070C 00C23021 */  addu      $a2, $a2, $v0
/* EC78C0 80240710 8CC6D2C0 */  lw        $a2, %lo(D_8008D2C0)($a2)
/* EC78C4 80240714 0C0B551A */  jal       func_802D5468
/* EC78C8 80240718 0220282D */   daddu    $a1, $s1, $zero
/* EC78CC 8024071C 8FBF0018 */  lw        $ra, 0x18($sp)
/* EC78D0 80240720 8FB10014 */  lw        $s1, 0x14($sp)
/* EC78D4 80240724 8FB00010 */  lw        $s0, 0x10($sp)
/* EC78D8 80240728 24020002 */  addiu     $v0, $zero, 2
/* EC78DC 8024072C 03E00008 */  jr        $ra
/* EC78E0 80240730 27BD0020 */   addiu    $sp, $sp, 0x20
/* EC78E4 80240734 00000000 */  nop       
/* EC78E8 80240738 00000000 */  nop       
/* EC78EC 8024073C 00000000 */  nop       
