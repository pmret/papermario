.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801369D0
/* CD0D0 801369D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD0D4 801369D4 3C04001D */  lui       $a0, 0x1d
/* CD0D8 801369D8 34840060 */  ori       $a0, $a0, 0x60
/* CD0DC 801369DC 24020034 */  addiu     $v0, $zero, 0x34
/* CD0E0 801369E0 24A5000C */  addiu     $a1, $a1, 0xc
/* CD0E4 801369E4 24C60004 */  addiu     $a2, $a2, 4
/* CD0E8 801369E8 240700FF */  addiu     $a3, $zero, 0xff
/* CD0EC 801369EC AFBF0018 */  sw        $ra, 0x18($sp)
/* CD0F0 801369F0 AFA20010 */  sw        $v0, 0x10($sp)
/* CD0F4 801369F4 0C04993B */  jal       draw_msg
/* CD0F8 801369F8 AFA00014 */   sw       $zero, 0x14($sp)
/* CD0FC 801369FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD100 80136A00 03E00008 */  jr        $ra
/* CD104 80136A04 27BD0020 */   addiu    $sp, $sp, 0x20
