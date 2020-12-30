.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218944_4E3084
/* 4E3084 80218944 3C048022 */  lui       $a0, %hi(D_80224D60)
/* 4E3088 80218948 8C844D60 */  lw        $a0, %lo(D_80224D60)($a0)
/* 4E308C 8021894C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4E3090 80218950 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4E3094 80218954 0C016914 */  jal       remove_effect
/* 4E3098 80218958 00000000 */   nop      
/* 4E309C 8021895C 3C048022 */  lui       $a0, %hi(D_80224D64)
/* 4E30A0 80218960 8C844D64 */  lw        $a0, %lo(D_80224D64)($a0)
/* 4E30A4 80218964 0C016914 */  jal       remove_effect
/* 4E30A8 80218968 00000000 */   nop      
/* 4E30AC 8021896C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4E30B0 80218970 24020002 */  addiu     $v0, $zero, 2
/* 4E30B4 80218974 03E00008 */  jr        $ra
/* 4E30B8 80218978 27BD0018 */   addiu    $sp, $sp, 0x18
/* 4E30BC 8021897C 00000000 */  nop       
